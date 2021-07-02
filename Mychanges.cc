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


//npy/NNodeNudger.cpp
void NNodeNudger::update_prim_bb()
{
    LOG(info) << "NNodeNudger::update_prim_bb nprim " << prim.size() ;
    zorder.clear();
    bb.clear();
    for(unsigned i=0 ; i < prim.size() ; i++)
    {
        const nnode* p = prim[i] ;
        LOG(debug) << "nnode p " << p->type;
        if( p->type!=0 ){ //exclude a node type 0 at here:867 soname Rich1MasterWithSubtract0x157230a0 lvname _dd_Geometry_BeforeMagnetRegion_Rich1_lvRich1Master0x15723290
        p->dump();
        nbbox pbb = p->bbox();
        bb.push_back(pbb);
        zorder.push_back(i);
        }
    ...
    }
    ...
}


//npy/NNode.cpp
float nnode::operator()(float , float , float ) const
{
    //assert(0 && "nnode::operator() needs override ");
    return 0.f ;
}
...
unsigned nnode::par_nsurf() const
{
    //assert(0 && "this need to be overridden");
    return 0 ;
}

//ggeo/GBndLib.cc
void GBndLib::fillMaterialLineMap( std::map<std::string, unsigned>& msu)
{
    // first occurence of a material within the boundaries
    // has its material line recorded in the MaterialLineMap

    for(unsigned int i=0 ; i < getNumBnd() ; i++)
    {
        const guint4& bnd = m_bnd[i] ;
        const char* omat = m_mlib->getName(bnd[OMAT]);
        const char* imat = m_mlib->getName(bnd[IMAT]);
        //assert(imat && omat);
        if(imat&&omat){
        if(msu.count(imat) == 0) msu[imat] = getLine(i, IMAT) ;
        if(msu.count(omat) == 0) msu[omat] = getLine(i, OMAT) ;
        }
    }
    ...
}
unsigned GBndLib::getMaterialLine(const char* shortname_)
{
    // used by App::loadGenstep for setting material line in TorchStep
    unsigned ni = getNumBnd();
    unsigned line = 0 ; 
    for(unsigned i=0 ; i < ni ; i++)    
    {
        const guint4& bnd = m_bnd[i] ;
        const char* omat = m_mlib->getName(bnd[OMAT]);
        const char* imat = m_mlib->getName(bnd[IMAT]);
        if(omat&&imat){
        if(strncmp(imat, shortname_, strlen(shortname_))==0)
        { 
            line = getLine(i, IMAT);  
            break ;
        }
        if(strncmp(omat, shortname_, strlen(shortname_))==0) 
        { 
            line=getLine(i, OMAT); 
            break ;
        } 
        }
    }
    ...
}

