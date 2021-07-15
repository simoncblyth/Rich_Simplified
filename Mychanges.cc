//sysrap/SAbbrev.cc
void SAbbrev::init()
{
    ...
    for(unsigned i=0 ; i < names.size() ; i++)
    {
        const char* name = names[i].c_str();
        SASCII* n = new SASCII(name);

        int chars_after_other = n->other == 1 ? strlen(name) - n->first_other_index - 1 : -1 ;   
        bool underscored = chars_after_other > 2 ;

        LOG(LEVEL)
           << " name [" << name << "]"
           << " n->other " << n->other
           << " chars_after_other " << chars_after_other
           ;


        // when have an underscore abbreviate the string after it
        if( underscored )
        {
            int idx = n->first_other_index ;
            delete n ;
            n = new SASCII(name+idx+1) ;
        }

        std::string ab ;

        if( n->upper == 1 && n->number > 0 ) // 1 or more upper and number
        {
            int iu = n->first_upper_index ;
            int in = n->first_number_index ;
            ab = n->getTwoChar( iu < in ? iu : in ,  iu < in ? in : iu  );
        }
        else if( n->upper >= 2 ) // more than one uppercase : form abbrev from first two uppercase chars
        {
            ab = n->getFirstUpper(n->upper) ;
        }
        else
        {
            ab = n->getFirst(2) ;
        }
        LOG(LEVEL)
            << " name [" << name << "]"
            << " ab [" << ab << "]"
            ;

        if(!isFree(ab))
        {
            ab = n->getFirstLast();
        }

        bool is_now_free = isFree(ab) ;

        LOG(LEVEL)
            << " name [" << name << "]"
            << " ab [" << ab << "]"
            << " is_now_free " << is_now_free
            ;

        assert( is_now_free && "failed to abbreviate ");
        abbrev.push_back(ab) ;
    }
}

//ggeo/GOpticalSurface.cc
bool GOpticalSurface::isSpecular() const
{
    if(strncmp(m_finish,"0",strlen(m_finish))==0)  return true ;
    if(strncmp(m_finish,"1",strlen(m_finish))==0)  return true ;  // used by JUNO.Mirror_opsurf m_finish 1
    if(strncmp(m_finish,"3",strlen(m_finish))==0)  return false ;
    if(strncmp(m_finish,"4",strlen(m_finish))==0)  return false ;

    LOG(info) << "GOpticalSurface::isSpecular "
              << " m_shortname " << ( m_shortname ? m_shortname : "-" )
              << " m_finish "    << ( m_finish ? m_finish : "-" )
              ;

    assert(0 && "expecting m_finish to be 0:polished or 3:ground ");
    return false ;
}

//extg4/X4Solid.cc
const bool X4Solid::convertPolycone_duplicate_py_inner_omission = true ;

void X4Solid::convertPolycone()
{
    ...
    float startphi = ph->Start_angle/degree ;
    float deltaphi = ph->Opening_angle/degree ;
    //assert( startphi == 0.f && deltaphi == 360.f );

    unsigned nz = ph->Num_z_planes ;
    ...
}

//npy/NCSG.cpp
NNodeNudger* NCSG::make_nudger(const char* msg) const
{
    // when test running from nnode there is no metadata or treedir
    LOG(LEVEL)
        <<  " lvIdx " << m_lvIdx
        //<<  " soname " << get_soname() 
        << " treeNameIdx " << getTreeNameIdx()
         ;

    NNodeNudger* nudger = new NNodeNudger(m_root, m_surface_epsilon, m_root->verbosity);
    return nudger ;
}

//npy/NTreeProcess.cpp
template <typename T>
unsigned NTreeProcess<T>::MaxHeight0 = 4 ;   // was discrepantly 4 previously  

//extg4/X4PhysicalVolume.cc
unsigned X4PhysicalVolume::addBoundary(const G4VPhysicalVolume* const pv, const G4VPhysicalVolume* const pv_p )
{
    const G4LogicalVolume* const lv   = pv->GetLogicalVolume() ;
    const G4LogicalVolume* const lv_p = pv_p ? pv_p->GetLogicalVolume() : NULL ;

    // GDMLName adds pointer suffix to the object name, returns null when object is null : eg parent of world 

    const char* _pv = X4::GDMLName(pv) ;
    const char* _pv_p = X4::GDMLName(pv_p) ;


    const G4Material* const imat_ = lv->GetMaterial() ;
    const G4Material* const omat_ = lv_p ? lv_p->GetMaterial() : imat_ ;  // top omat -> imat 

    std::string omat_name = X4::BaseName(omat_);
    boost::replace_all(omat_name,"_dd_Materials_","");
    boost::replace_all(omat_name,"RichMaterials_","");
    boost::replace_all(omat_name,"Pipe_","");
    boost::replace_all(omat_name,"Velo_","");
    std::string imat_name = X4::BaseName(imat_);
    boost::replace_all(imat_name,"_dd_Materials_","");
    boost::replace_all(imat_name,"RichMaterials_","");
    boost::replace_all(imat_name,"Pipe_","");
    boost::replace_all(imat_name,"Velo_","");

    const char* omat = strdup( omat_name.c_str() ) ;
    const char* imat = strdup( imat_name.c_str() ) ;
    ...
}

//ok/OKMgr.cc
OKMgr::OKMgr(int argc, char** argv, const char* argforced ) 
    : 
    m_log(new SLog("OKMgr::OKMgr","", debug)), 
    m_ok(Opticks::HasInstance() ? Opticks::GetInstance() : new Opticks(argc, argv, argforced)), 
    m_hub(new OpticksHub(m_ok)),            // immediate configure and loadGeometry  
    m_idx(new OpticksIdx(m_hub)), 
    m_num_event(m_ok->getMultiEvent()),     // after hub instanciation, as that configures Opticks 
    m_gen(m_hub->getGen()), 
    m_run(m_ok->getRun()), 
    //m_viz(m_ok->isCompute() ? NULL : new OpticksViz(m_hub, m_idx, true)), 
    m_viz(new OpticksViz(m_hub, m_idx, true)), //always do the visualization
    m_propagator(new OKPropagator(m_hub, m_idx, m_viz)), 
    m_count(0) 
{ 
    init(); 
    (*m_log)("DONE"); 
} 

//optixrap/OContext.cc
void OContext::CheckDevices(Opticks* ok)
{
    VisibleDevices vdev ;
    LOG(info) << std::endl << vdev.desc();

    BMeta* parameters = ok->getParameters();
    parameters->add<int>("NumDevices", vdev.num_devices );
    parameters->add<std::string>("VisibleDevices", vdev.brief() );

    const char* frame_renderer = Opticks::Instance()->getFrameRenderer();
    if( frame_renderer != NULL)
    {
        if(vdev.num_devices != 1) LOG(fatal) << "vdev.num_devices " << vdev.num_devices ;
        assert( vdev.num_devices == 1 && "expecting only a single visible device, the one driving the display, in interop mode") ;
        const char* optix_device = vdev.devices[0].name ;
        LOG(LEVEL) << " frame_renderer " << frame_renderer ;
        LOG(LEVEL) << " optix_device " << optix_device  ;
        bool interop_device_match = SStr::Contains( frame_renderer, optix_device )  ;
        //assert( interop_device_match && "OpenGL and OptiX must be talking to the same single device in interop mode"  ); 

        parameters->add<std::string>("FrameRenderer", frame_renderer ); 
    }
    else 
    { 
        LOG(LEVEL) << " NULL frame_renderer : compute mode ? " ; 
    } 
}

//optickscore/OpticksMode.cc 
int OpticksMode::getInteractivityLevel() const 
{ 
    int interactivity = SSys::GetInteractivityLevel() ; 
    if(m_noviz) interactivity = 0 ; 
    if(isCompute()) interactivity = 0 ;  
    //return interactivity  ; 
    return 1  ; // always do the visualization 
}

//ggeo/GMeshLib.cc
void GMeshLib::loadAltReferences() 
{
    for(unsigned i=0 ; i < m_meshes.size() ; i++ )
    {
        const GMesh* mesh = m_meshes[i] ; 
        const NCSG* solid = i < m_solids.size() ? m_solids[i] : NULL ;  
        assert( mesh->getCSG() == solid ); 
        if(solid == NULL) continue ;  
        if( mesh->getAlt()==NULL ) continue ; // To be consistent with GMeshLib::saveAltReferences() 
        int altindex = solid->get_altindex();  
        if(altindex == -1) continue ; 
     
        assert( unsigned(altindex) < m_meshes.size() ); 
        const GMesh* alt = m_meshes[altindex] ; 
        const_cast<GMesh*>(mesh)->setAlt(alt) ;            
        LOG(LEVEL) 
            << " mesh.i " << i 
            << " altindex " << altindex ; 
            ;
    }
}

//ggeo/GParts.cc
GParts* GParts::Create(const Opticks* ok, const GPts* pts, const std::vector<const NCSG*>& solids, unsigned* num_mismatch_pt, std::vector<glm::mat4>* mismatch_placements ) // static
{
    ...
    for(unsigned i=0 ; i < num_pt ; i++)
    {
        const GPt* pt = pts->getPt(i);
        int   lvIdx = pt->lvIdx ;
        int   ndIdx = pt->ndIdx ;
        const std::string& spec = pt->getSpec() ;
        const glm::mat4& placement = pt->getPlacement() ;

        LOG(level)
            << " pt " << std::setw(4)
            << " lv " << std::setw(4) << lvIdx
            << " nd " << std::setw(6) << ndIdx
            << " pl " << GLMFormat::Format(placement)
            << " bn " << spec
            ;

        assert( lvIdx > -1 );

        //const NCSG* csg = unsigned(lvIdx) < solids.size() ? solids[lvIdx] : NULL ; 
        const NCSG* csg = unsigned(lvIdx) < solids.size() ? solids[lvIdx] : solids[solids.size()-1] ; // lvIdx can be 868, but solids.size==300
        assert( csg );
        ...
    }
}
