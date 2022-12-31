#pragma once
#include <array>
#include <iosfwd>

namespace OptiTake
{
    struct Tile
    {
        int x;
        int y;
        int z;

        auto operator<=>(Tile const &) const = default;
    };

    std::ostream &operator<<(std::ostream &strm, Tile const &t);

    static constexpr std::array<Tile, 27> allPossibleTiles{ 
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