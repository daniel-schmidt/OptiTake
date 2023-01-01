#include "Tile.h" 

#include <iostream>

namespace OptiTake
{
    std::ostream & operator<< (std::ostream & strm, Tile const &t)
    {
        strm << t.x << ", " << t.y << ", " << t.z;
        return strm;
    }

    bool Tile::empty() const
    {
        return x == -1 || y == -1 || z == -1;
    }

    std::string ToString(Tile const &t, Axis ax) 
    {
      switch (ax) {
      case Axis::x:
        return t.empty() ? " " : std::to_string(t.x);
      case Axis::y:
        return t.empty() ? "_" : std::to_string(t.y);
      case Axis::z:
        return t.empty() ? "_" : std::to_string(t.z);
      }
    }
} // namespace OptiTake