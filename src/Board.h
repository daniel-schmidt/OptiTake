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

    [[nodiscard]] int GetScore() const;

    friend std::ostream & operator<<(std::ostream & strm, Board const & board)
    {
        // drawing the board as ascii art with the chosen tiles filled in or empty
        strm << "         ___\n";
        strm << "     ___/ " << ToString(board.tiles[2][0], Axis::x) <<  " \\___\n";
        strm << " ___/ " << ToString(board.tiles[1][0], Axis::x) << " \\" << ToString(board.tiles[2][0], Axis::y) << "_" << ToString(board.tiles[2][0], Axis::z) << "/ " << ToString(board.tiles[3][0], Axis::x) << " \\___\n";
        strm << "/ " << ToString(board.tiles[0][0], Axis::x) << " \\" << ToString(board.tiles[1][0], Axis::y) << "_" << ToString(board.tiles[1][0], Axis::z) << "/ " << ToString(board.tiles[2][1], Axis::x) << " \\" << ToString(board.tiles[3][0], Axis::y) << "_" << ToString(board.tiles[3][0], Axis::z) << "/ " << ToString(board.tiles[4][0], Axis::x) << " \\\n";
        strm << "\\" << ToString(board.tiles[0][0], Axis::y) << "_" << ToString(board.tiles[0][0], Axis::z) << "/ " << ToString(board.tiles[1][1], Axis::x) << " \\" << ToString(board.tiles[2][1], Axis::y) << "_" << ToString(board.tiles[2][1], Axis::z) << "/ " << ToString(board.tiles[3][1], Axis::x) << " \\" << ToString(board.tiles[4][0], Axis::y) << "_" << ToString(board.tiles[4][0], Axis::z) << "/\n";
        strm << "/ " << ToString(board.tiles[0][1], Axis::x) << " \\" << ToString(board.tiles[1][1], Axis::y) << "_" << ToString(board.tiles[1][1], Axis::z) << "/ " << ToString(board.tiles[2][2], Axis::x) << " \\" << ToString(board.tiles[3][1], Axis::y) << "_" << ToString(board.tiles[3][1], Axis::z) << "/ " << ToString(board.tiles[4][1], Axis::x) << " \\\n";
        strm << "\\" << ToString(board.tiles[0][1], Axis::y) << "_" << ToString(board.tiles[0][1], Axis::z) << "/ " << ToString(board.tiles[1][2], Axis::x) << " \\" << ToString(board.tiles[2][2], Axis::y) << "_" << ToString(board.tiles[2][2], Axis::z) << "/ " << ToString(board.tiles[3][2], Axis::x) << " \\" << ToString(board.tiles[4][1], Axis::y) << "_" << ToString(board.tiles[4][1], Axis::z) << "/\n";
        strm << "/ " << ToString(board.tiles[0][2], Axis::x) << " \\" << ToString(board.tiles[1][2], Axis::y) << "_" << ToString(board.tiles[1][2], Axis::z) << "/ " << ToString(board.tiles[2][3], Axis::x) << " \\" << ToString(board.tiles[3][2], Axis::y) << "_" << ToString(board.tiles[3][2], Axis::z) << "/ " << ToString(board.tiles[4][2], Axis::x) << " \\\n";
        strm << "\\" << ToString(board.tiles[0][2], Axis::y) << "_" << ToString(board.tiles[0][2], Axis::z) << "/ " << ToString(board.tiles[1][3], Axis::x) << " \\" << ToString(board.tiles[2][3], Axis::y) << "_" << ToString(board.tiles[2][3], Axis::z) << "/ " << ToString(board.tiles[3][3], Axis::x) << " \\" << ToString(board.tiles[4][2], Axis::y) << "_" << ToString(board.tiles[4][2], Axis::z) << "/\n";
        strm << "    \\" << ToString(board.tiles[1][3], Axis::y) << "_" << ToString(board.tiles[1][3], Axis::z) << "/ " << ToString(board.tiles[2][4], Axis::x) << " \\" << ToString(board.tiles[3][3], Axis::y) << "_" << ToString(board.tiles[3][3], Axis::z) << "/\n";
        strm << "        \\" << ToString(board.tiles[2][4], Axis::y) << "_" << ToString(board.tiles[2][4], Axis::z) << "/\n";
        return strm;
    }

private:
    // there are 5 columns with different length (3, 4, 5, 4, 3)
    using ColumnT = std::vector<Tile>;
    std::array<ColumnT, 5> tiles;
};

}