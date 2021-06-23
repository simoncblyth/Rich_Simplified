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

//ggeo/X4Solid.cc
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
