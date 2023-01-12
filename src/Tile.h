#pragma once
#include <array>
#include <iosfwd>
#include <string>

namespace OptiTake
{
    struct Tile
    {
        int x = -1;
        int y = -1;
        int z = -1;

        [[nodiscard]] bool empty() const;

        auto operator<=>(Tile const &) const = default;
    };

    // for printing the current tile on the console
    std::ostream &operator<<(std::ostream &strm, Tile const &t);
    
    // to display the numbers in the tile at the correct position
    enum class Axis{ x, y, z };

    // to draw the tiles on the board, either empty or filled
    std::string ToString(Tile const &t, Axis ax);

    // all 27 tiles existing in the game
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