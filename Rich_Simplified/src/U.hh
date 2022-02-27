#pragma once

#include <cstdlib>
#include <string>
#include <sstream>

struct U
{
    static int atoi_( const char* a )
    {
        std::string s(a);
        std::istringstream iss(s);
        int i ;
        iss >> i ;
        return i ;
    }

    static int getenvint( const char* envkey, int fallback )
    {
        char* val = getenv(envkey);
        int ival = val ? atoi_(val) : fallback ;
        return ival ; 
    }
};



