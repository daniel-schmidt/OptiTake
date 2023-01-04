#include "Tile.h" 

#include <iostream>
#include <cassert>

namespace OptiTake
{
    std::ostream & operator<< (std::ostream & strm, Tile const &t)
    {
        // to print the chosen tile on the console
        strm << " ___\n";
        strm << "/ " << t.x << " \\ \n";
        strm << "\\" << t.y << "_" << t.z << "/\n";
        return strm;
    }

    bool Tile::empty() const
    {
        // needed for displaying empty tiles in the board
        return x == -1 || y == -1 || z == -1;
    }

    std::string ToString(Tile const &t, Axis ax) 
    {
      /*
      * When the board is drawn on the console, the tiles are represented as boxes: 
      * empty:  ___   filled: ___
      *        /   \         / x \
      *        \___/         \y_z/
      * To display the tile correctly, unfilled positions are shown empty.
      * When filled, the x, y and z are filled with the corresponding numbers of the tile.
      */
      switch (ax) {
      case Axis::x:
        return t.empty() ? " " : std::to_string(t.x);
      case Axis::y:
        return t.empty() ? "_" : std::to_string(t.y);
      case Axis::z:
        return t.empty() ? "_" : std::to_string(t.z);
      default:
        assert(false);
        return "";
      }
    }
} // namespace OptiTake