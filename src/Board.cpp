#include "Board.h"
#include <optional>

namespace OptiTake 
{
    Board::Board() 
    {
        tiles[0] = {3, Tile{}};
        tiles[1] = {4, Tile{}};
        tiles[2] = {5, Tile{}};
        tiles[3] = {4, Tile{}};
        tiles[4] = {3, Tile{}};
    }


    bool Board::SetTileToPosition(Tile const &newTile, BoardPosition pos)
    {
        if(pos.colIndex < 0 || pos.colIndex > 4) {
            return false;
        }

        auto & currentCol = tiles[pos.colIndex];
        if(pos.posInCol < 0 || pos.posInCol > currentCol.size() -1 ) {
            return false;
        }

        auto & tileAtPos = currentCol[pos.posInCol];
        if(!tileAtPos.empty()) {
            return false;
        }

        tileAtPos = newTile;
        return true;
    }
} // namespace OptiTake