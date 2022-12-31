#pragma once
#include "Tile.h"

#include <array>
#include <ostream>
#include <vector>
#include <optional>

namespace OptiTake
{

struct BoardPosition
{
    int colIndex;
    int posInCol;
};


class Board
{
public: 
    Board();
    [[nodiscard]] bool SetTileToPosition(Tile const &newTile, BoardPosition pos);

    friend std::ostream & operator<<(std::ostream & strm, Board const & board)
    {
        strm << ToString(board.tiles[0][0], Axis::x);
        return strm;
    }

private:
    using ColumnT = std::vector<Tile>;
    std::array<ColumnT, 5> tiles;
};

}