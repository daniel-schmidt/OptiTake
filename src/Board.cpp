#include "Board.h"
#include <algorithm>
#include <cstddef>
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
                return sum + static_cast<int>(col.size()) * col[0].x;   
            }
            return sum;
        }
        
        int CalculateValueY(int sum, std::vector<Tile> const & col)
        {
            if(!col[0].empty() && std::ranges::all_of(col, IsEqualTo(col[0].y), &Tile::y)) {
                return sum + static_cast<int>(col.size()) * col[0].y;   
            }
            return sum;
        }

        int CalculateValueZ(int sum, std::vector<Tile> const & col)
        {
            if(!col[0].empty() && std::ranges::all_of(col, IsEqualTo(col[0].z), &Tile::z)) {
                return sum + static_cast<int>(col.size()) * col[0].z;   
            }
            return sum;
        }

        bool IsValidColumn(int index){
            return index >= 0 && index <= 4;
        }

        bool IsValidPosInCol(int posInCol, ptrdiff_t currentColSize){
            return posInCol >= 0 && posInCol <= currentColSize -1;
        }

        bool IsFreePosition(OptiTake::Tile const & tileAtPos){
            return tileAtPos.empty();
        }
    }


    BoardPosition::BoardPosition(int colIndex, int posInCol)
        : colIndex(colIndex), posInCol(posInCol) 
    {
        if (colIndex < 0 || posInCol < 0) {
            throw std::out_of_range{"Expected minimum of 0 for 0-based indices."};
        }
        if (colIndex > 4 || posInCol > 4) {
            throw std::out_of_range{"Expected maximum of 4 for 0-based indices."};
        }
    }


    BoardPositionOneBased::BoardPositionOneBased(BoardPosition const &source)
        : colIndex(source.GetColIndex() + 1)
        , posInCol(source.GetPosInCol() + 1)
    {
        if (colIndex < 1 || posInCol < 1) {
            throw std::out_of_range{"Expected minimum of 1 for 1-based indices."};
        }
        if (colIndex > 5 || posInCol > 5) {
            throw std::out_of_range{"Expected maximum of 5 for 1-based indices."};
        }
    }


    std::ostream &operator<<(std::ostream &stream, BoardPositionOneBased const &pos)
    {
        stream << "{" << pos.GetColIndex() << ", " << pos.GetPosInCol() << "}";
        return stream;
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

    Board::Board(std::array<Tile, 19> const & tilesPerRow)
    {
        tiles[0].insert(tiles[0].begin(), tilesPerRow.begin(), tilesPerRow.begin()+3);
        tiles[1].insert(tiles[1].begin(), tilesPerRow.begin()+3, tilesPerRow.begin()+7);
        tiles[2].insert(tiles[2].begin(), tilesPerRow.begin()+7, tilesPerRow.begin()+12);
        tiles[3].insert(tiles[3].begin(), tilesPerRow.begin()+12, tilesPerRow.begin()+16);
        tiles[4].insert(tiles[4].begin(), tilesPerRow.begin()+16, tilesPerRow.end());
    }


    bool Board::SetTileToPosition(Tile const &newTile, BoardPosition pos)
    {
        if (!IsValidColumn(pos.GetColIndex())){
            return false;
        }

        auto & currentCol = tiles[pos.GetColIndex()];
        if (!IsValidPosInCol(pos.GetPosInCol(), std::ssize(currentCol))){
            return false;
        }

        auto & tileAtPos = currentCol[pos.GetPosInCol()];
        if (!IsFreePosition(tileAtPos)){
            return false;
        }

        tileAtPos = newTile;
        return true;
    }


    std::optional<BoardPosition> Board::Find(Tile const &to_find) const
    {
        int col_counter = 0;
        for (auto const & col : tiles) {
            if(auto const found_it = std::ranges::find(col, to_find); found_it != col.end()) {
                auto const row_pos = static_cast<int>(std::distance(col.begin(), found_it));
                return BoardPosition{col_counter, row_pos};
            }
            col_counter++;
        }
        return {};
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
            ColumnT{ tiles[0][1], tiles[1][1], tiles[2][1], tiles[3][0]},
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

    std::vector<BoardPosition> Board::GetFreePositions() const 
    {
        std::vector<BoardPosition> free;
        int col_counter = 0;
        for (auto const & column : tiles) {
            int row_counter = 0;
            for (auto const & tile : column) {
                if (tile.empty()) {
                    free.emplace_back(col_counter, row_counter);
                }
                row_counter++;
            }
            col_counter++;
        }
        return free;
    }

    bool Board::IsFree(BoardPosition const & position) const
    {
        return tiles[position.GetColIndex()][position.GetPosInCol()].empty();
    }

    } // namespace OptiTake