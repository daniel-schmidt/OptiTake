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
        if(board.tiles[0][0].has_value()) {
            strm << board.tiles[0][0]->x;
        }
        return strm;
    }
    
private:
    using ColumnT = std::vector<std::optional<Tile>>;
    std::array<ColumnT, 5> tiles;
};

}