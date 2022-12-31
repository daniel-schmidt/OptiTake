#include "Tile.h" 

#include <iostream>

namespace OptiTake
{
    std::ostream & operator<< (std::ostream & strm, Tile const &t)
    {
        strm << t.x << ", " << t.y << ", " << t.z;
        return strm;
    }
}