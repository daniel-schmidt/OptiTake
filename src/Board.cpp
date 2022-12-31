#include "Board.h"
#include <algorithm>
#include <numeric>
#include <optional>

namespace OptiTake 
{
    namespace 
    {
        auto IsEqualTo(int expected)
        {
            return [=](int coord){ return coord == expected;};
        }

        int CalculateValueX(int sum, std::vector<Tile> const & col)
        {
            if(!col[0].empty() && std::ranges::all_of(col, IsEqualTo(col[0].x), &Tile::x)) {
                return sum + col.size() * col[0].x;   
            }
            return sum;
        }
        
        int CalculateValueY(int sum, std::vector<Tile> const & col)
        {
            if(!col[0].empty() && std::ranges::all_of(col, IsEqualTo(col[0].y), &Tile::y)) {
                return sum + col.size() * col[0].y;   
            }
            return sum;
        }

        int CalculateValueZ(int sum, std::vector<Tile> const & col)
        {
            if(!col[0].empty() && std::ranges::all_of(col, IsEqualTo(col[0].z), &Tile::z)) {
                return sum + col.size() * col[0].z;   
            }
            return sum;
        }

    }

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


    int Board::GetScore() const 
    {        
        std::array<ColumnT, 5> transposedLeft = { 
            ColumnT{ tiles[0][2], tiles[1][3], tiles[2][4] },
            ColumnT{ tiles[0][1], tiles[1][2], tiles[2][3], tiles[3][3]},
            ColumnT{ tiles[0][0], tiles[1][1], tiles[2][2], tiles[3][2], tiles[4][2] },
            ColumnT{              tiles[1][0], tiles[2][1], tiles[3][1], tiles[4][1] },
            ColumnT{                           tiles[2][0], tiles[3][0], tiles[4][0] }
        };
     
        std::array<ColumnT, 5> transposedRight = { 
            ColumnT{ tiles[0][0], tiles[1][0], tiles[2][0] },
            ColumnT{ tiles[0][1], tiles[1][1], tiles[2][1], tiles[3][1]},
            ColumnT{ tiles[0][2], tiles[1][2], tiles[2][2], tiles[3][1], tiles[4][0] },
            ColumnT{              tiles[1][3], tiles[2][3], tiles[3][2], tiles[4][1] },
            ColumnT{                           tiles[2][4], tiles[3][3], tiles[4][2] }
        };
        
        int score = std::accumulate(tiles.begin(), tiles.end(), 0, CalculateValueX);
        score = std::accumulate(transposedRight.begin(), transposedRight.end(), score, CalculateValueY);
        score = std::accumulate(transposedLeft.begin(), transposedLeft.end(), score, CalculateValueZ);

        return score;
    }
} // namespace OptiTake