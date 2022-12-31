#include <iostream>
#include <string>
#include <array>

namespace
{
    struct Tile
    {
        int x;
        int y;
        int z;
    };


    std::ostream & operator<<(std::ostream & strm, Tile const & t)
    {
        strm << t.x << ", " << t.y << ", " << t.z;
        return strm;
    }


    std::array<Tile, 27> allPossibleTiles{ 
        Tile{1, 2, 3}, 
        {1, 2, 4},
        {1, 2, 8},
        {1, 6, 3}, 
        {1, 6, 4},
        {1, 6, 8},
        {1, 7, 3}, 
        {1, 7, 4},
        {1, 7, 8},
        {5, 2, 3}, 
        {5, 2, 4},
        {5, 2, 8},
        {5, 6, 3}, 
        {5, 6, 4},
        {5, 6, 8},
        {5, 7, 3}, 
        {5, 7, 4},
        {5, 7, 8},
        {9, 2, 3}, 
        {9, 2, 4},
        {9, 2, 8},
        {9, 6, 3}, 
        {9, 6, 4},
        {9, 6, 8},
        {9, 7, 3}, 
        {9, 7, 4},
        {9, 7, 8}};
}


int main()
{
    Tile const t = allPossibleTiles[23];    
    std::cout << "Hello Daniel. Du hast " << t << " gezogen!\n";
}