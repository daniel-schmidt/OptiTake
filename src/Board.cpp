#include "Board.h"
#include <optional>

namespace OptiTake 
{
    Board::Board() 
    {
        tiles[0] = {3, std::nullopt};
        tiles[1] = {4, std::nullopt};
        tiles[2] = {5, std::nullopt};
        tiles[3] = {4, std::nullopt};
        tiles[4] = {3, std::nullopt};
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
        if(tileAtPos.has_value()) {
            return false;
        }
        
        tileAtPos = newTile;
        return true;
    }
} // namespace OptiTake