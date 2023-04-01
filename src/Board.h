#pragma once
#include "Tile.h"

#include <array>
#include <optional>
#include <ostream>
#include <vector>

namespace OptiTake
{

struct BoardPosition
{
    int colIndex;
    int posInCol;

    auto operator<=>(BoardPosition const &) const = default;
};

std::ostream &operator<<(std::ostream &stream, BoardPosition const &pos);

class Board
{
public: 
    Board();
    Board(std::array<Tile, 19> const & tilesPerRow);

    /**
     * @brief Adds a new tile to the board at the given position.
     *
     * @param newTile the new tile to set on the board
     * @param pos the position where to put the tile
     * @returns true if the tile could be set, false if the position was invalid or alread occupied.
     */
    [[nodiscard]] bool SetTileToPosition(Tile const &newTile, BoardPosition pos);

    /**
     * @brief Looks for the given tile in the current board.
     *
     * @param to_find is the Tile to find in the board.
     * @returns the position if the board contains the tile, otherwise returns std::nullopt.
     */
    [[nodiscard]] std::optional<BoardPosition> Find(Tile const &to_find);

    /**
     * @brief The points are calculated for each direction. 
     * Points are only given, when all numbers per column/diagonal are equal.
     * The points given are the number in that column/diagonal multiplied by number of tiles.
     *
     * @returns score
     */
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


inline static Board optimal_board{std::array<Tile, 19>{Tile
        {5,6,3}, {5,6,4}, {5,2,8},
        {9,6,8}, {9,6,3}, {9,2,4}, {9,7,8},
        {1,6,4}, {1,6,8}, {1,2,3}, {1,7,4}, {1,7,8},
        {9,6,4}, {9,2,8}, {9,7,3}, {9,7,4}, 
        {5,2,4}, {5,7,8}, {5,7,3}
    }};

}