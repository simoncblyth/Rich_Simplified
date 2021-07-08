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

//npy/GGeo.cc
void GGeo::postDirectTranslation()
{
    LOG(LEVEL) << "[" ;

    prepare();     // instances are formed here     

    LOG(LEVEL) << "( GBndLib::fillMaterialLineMap " ;
    //GBndLib* blib = getBndLib();
    //blib->fillMaterialLineMap();
    LOG(LEVEL) << ") GBndLib::fillMaterialLineMap " ;

    LOG(LEVEL) << "( GGeo::save " ;
    save();
    LOG(LEVEL) << ") GGeo::save " ;


    deferred();

    postDirectTranslationDump();

    LOG(LEVEL) << "]" ;
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
NPY<float>* GBndLib::createBufferForTex2d()
{
    ...
        for(unsigned int i=0 ; i < ni ; i++)      // over bnd
    {
        const guint4& bnd = m_bnd[i] ;
        for(unsigned j=0 ; j < nj ; j++)     // over imat/omat/isur/osur species
        {
            unsigned wof = nj*nk*nl*nm*i + nk*nl*nm*j ;

            if(j == IMAT || j == OMAT)
            {
                unsigned midx = bnd[j] ;
                if(midx != UNSET)
                {
                    unsigned mof = nk*nl*nm*midx ;
                    memcpy( wdat+wof, mdat+mof, sizeof(float)*nk*nl*nm );
                }
                else
                {
                    LOG(fatal) << "GBndLib::createBufferForTex2d"
                                 << " ERROR IMAT/OMAT with UNSET MATERIAL "
                                 << " i " << i
                                 << " j " << j
                                 ;
                    //assert(0);
                }
            }
    ...
        }
    }
}
NPY<unsigned>* GBndLib::createOpticalBuffer()
{
    ...
    for(unsigned i=0 ; i < ni ; i++)      // over bnd
    {
        const guint4& bnd = m_bnd[i] ;

        for(unsigned j=0 ; j < nj ; j++)  // over imat/omat/isur/osur
        {
            unsigned offset = nj*nk*i+nk*j ;
            if(j == IMAT || j == OMAT)
            {
                unsigned midx = bnd[j] ;
                //assert(midx != UNSET);

                odat[offset+0] = one_based ? midx + 1 : midx  ;
                odat[offset+1] = 0u ;
                odat[offset+2] = 0u ;
                odat[offset+3] = 0u ;

            }
        ...
        }
    }
}

