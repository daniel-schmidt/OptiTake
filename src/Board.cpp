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

        /*
        * The points are calculated for each direction. 
        * The tile axis x represents columns.
        * The tile axis y represents diagonals going up.
        * The tile axis z represents diagonals going down.
        * Points are only given, when all numbers per column/diagonal are equal.
        * The points given are the number in that column/diagonal multiplied by number of tiles.
        */
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
        // the board has 5 columns with 3, 4, 5, 4, 3 length
        tiles[0] = {3, Tile{}};
        tiles[1] = {4, Tile{}};
        tiles[2] = {5, Tile{}};
        tiles[3] = {4, Tile{}};
        tiles[4] = {3, Tile{}};
    }


    bool Board::SetTileToPosition(Tile const &newTile, BoardPosition pos)
    {
        // check if column index exists
        if(pos.colIndex < 0 || pos.colIndex > 4) {
            return false;
        }

        // check if row in this column exists
        auto & currentCol = tiles[pos.colIndex];
        if(pos.posInCol < 0 || pos.posInCol > currentCol.size() -1 ) {
            return false;
        }

        // check if the position is already filled
        auto & tileAtPos = currentCol[pos.posInCol];
        if(!tileAtPos.empty()) {
            return false;
        }

        tileAtPos = newTile;
        return true;
    }


    int Board::GetScore() const 
    {        
        // for axis z
        std::array<ColumnT, 5> transposedLeft = { 
            ColumnT{ tiles[0][2], tiles[1][3], tiles[2][4] },
            ColumnT{ tiles[0][1], tiles[1][2], tiles[2][3], tiles[3][3]},
            ColumnT{ tiles[0][0], tiles[1][1], tiles[2][2], tiles[3][2], tiles[4][2] },
            ColumnT{              tiles[1][0], tiles[2][1], tiles[3][1], tiles[4][1] },
            ColumnT{                           tiles[2][0], tiles[3][0], tiles[4][0] }
        };
     
        // for axis y
        std::array<ColumnT, 5> transposedRight = { 
            ColumnT{ tiles[0][0], tiles[1][0], tiles[2][0] },
            ColumnT{ tiles[0][1], tiles[1][1], tiles[2][1], tiles[3][1]},
            ColumnT{ tiles[0][2], tiles[1][2], tiles[2][2], tiles[3][1], tiles[4][0] },
            ColumnT{              tiles[1][3], tiles[2][3], tiles[3][2], tiles[4][1] },
            ColumnT{                           tiles[2][4], tiles[3][3], tiles[4][2] }
        };
        
        // calculate score for each axis and add them up.
        int score = std::accumulate(tiles.begin(), tiles.end(), 0, CalculateValueX);
        score = std::accumulate(transposedRight.begin(), transposedRight.end(), score, CalculateValueY);
        score = std::accumulate(transposedLeft.begin(), transposedLeft.end(), score, CalculateValueZ);

        return score;
    }
} // namespace OptiTake