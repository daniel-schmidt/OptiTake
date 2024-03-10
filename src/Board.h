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
public:
  explicit(false) BoardPosition(int colIndex, int posInCol);

  auto operator<=>(BoardPosition const &) const = default;

  inline int GetPosInCol() const { return posInCol; }
  inline int GetColIndex() const { return colIndex; }
 
private:
  int colIndex; ///< 0-based column index
  int posInCol; ///< 0-based position inside the column

};


struct BoardPositionOneBased
{
public:
    explicit(false) BoardPositionOneBased(BoardPosition const &source);
    
    inline int GetPosInCol() const { return posInCol; }
    inline int GetColIndex() const { return colIndex; }
private:
    int colIndex; ///< 1-based column index
    int posInCol; ///< 1-based position inside the column
};

std::ostream &operator<<(std::ostream &stream, BoardPositionOneBased const &pos);

class Board
{
public: 
    Board();
    explicit Board(std::array<Tile, 19> const & tilesPerRow);

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
    [[nodiscard]] std::optional<BoardPosition> Find(Tile const &to_find) const;

    /**
     * @brief The points are calculated for each direction. 
     * Points are only given, when all numbers per column/diagonal are equal.
     * The points given are the number in that column/diagonal multiplied by number of tiles.
     *
     * @returns score
     */
    [[nodiscard]] int GetScore() const;

    /**
     * @returns a list of all board positions without a tile.
     */
    [[nodiscard]] std::vector<BoardPosition> GetFreePositions() const;

    friend std::ostream & operator<<(std::ostream & strm, Board const & board)
    {
        using enum OptiTake::Axis;
        // drawing the board as ascii art with the chosen tiles filled in or empty
        strm << "         ___\n";
        strm << "     ___/ " << ToString(board.tiles[2][0], x) <<  " \\___\n";
        strm << " ___/ " << ToString(board.tiles[1][0], x) << " \\" << ToString(board.tiles[2][0], y) << "_" << ToString(board.tiles[2][0], z) << "/ " << ToString(board.tiles[3][0], x) << " \\___\n";
        strm << "/ " << ToString(board.tiles[0][0], x) << " \\" << ToString(board.tiles[1][0], y) << "_" << ToString(board.tiles[1][0], z) << "/ " << ToString(board.tiles[2][1], x) << " \\" << ToString(board.tiles[3][0], y) << "_" << ToString(board.tiles[3][0], z) << "/ " << ToString(board.tiles[4][0], x) << " \\\n";
        strm << "\\" << ToString(board.tiles[0][0], y) << "_" << ToString(board.tiles[0][0], z) << "/ " << ToString(board.tiles[1][1], x) << " \\" << ToString(board.tiles[2][1], y) << "_" << ToString(board.tiles[2][1], z) << "/ " << ToString(board.tiles[3][1], x) << " \\" << ToString(board.tiles[4][0], y) << "_" << ToString(board.tiles[4][0], z) << "/\n";
        strm << "/ " << ToString(board.tiles[0][1], x) << " \\" << ToString(board.tiles[1][1], y) << "_" << ToString(board.tiles[1][1], z) << "/ " << ToString(board.tiles[2][2], x) << " \\" << ToString(board.tiles[3][1], y) << "_" << ToString(board.tiles[3][1], z) << "/ " << ToString(board.tiles[4][1], x) << " \\\n";
        strm << "\\" << ToString(board.tiles[0][1], y) << "_" << ToString(board.tiles[0][1], z) << "/ " << ToString(board.tiles[1][2], x) << " \\" << ToString(board.tiles[2][2], y) << "_" << ToString(board.tiles[2][2], z) << "/ " << ToString(board.tiles[3][2], x) << " \\" << ToString(board.tiles[4][1], y) << "_" << ToString(board.tiles[4][1], z) << "/\n";
        strm << "/ " << ToString(board.tiles[0][2], x) << " \\" << ToString(board.tiles[1][2], y) << "_" << ToString(board.tiles[1][2], z) << "/ " << ToString(board.tiles[2][3], x) << " \\" << ToString(board.tiles[3][2], y) << "_" << ToString(board.tiles[3][2], z) << "/ " << ToString(board.tiles[4][2], x) << " \\\n";
        strm << "\\" << ToString(board.tiles[0][2], y) << "_" << ToString(board.tiles[0][2], z) << "/ " << ToString(board.tiles[1][3], x) << " \\" << ToString(board.tiles[2][3], y) << "_" << ToString(board.tiles[2][3], z) << "/ " << ToString(board.tiles[3][3], x) << " \\" << ToString(board.tiles[4][2], y) << "_" << ToString(board.tiles[4][2], z) << "/\n";
        strm << "    \\" << ToString(board.tiles[1][3], y) << "_" << ToString(board.tiles[1][3], z) << "/ " << ToString(board.tiles[2][4], x) << " \\" << ToString(board.tiles[3][3], y) << "_" << ToString(board.tiles[3][3], z) << "/\n";
        strm << "        \\" << ToString(board.tiles[2][4], y) << "_" << ToString(board.tiles[2][4], z) << "/\n";
        return strm;
    }

private:
    // there are 5 columns with different length (3, 4, 5, 4, 3)
    using ColumnT = std::vector<Tile>;
    std::array<ColumnT, 5> tiles;
};

// all 19 boardPositions existing in the game
inline static const std::array<BoardPosition, 19> allPossiblePositions{
    BoardPosition{0, 0},
    {0, 1},
    {0, 2},
    {1, 0},
    {1, 1}, 
    {1, 2}, 
    {1, 3},
    {2, 0}, 
    {2, 1}, 
    {2, 2}, 
    {2, 3}, 
    {2, 4},
    {3, 0}, 
    {3, 1}, 
    {3, 2}, 
    {3, 3}, 
    {4, 0}, 
    {4, 1}, 
    {4, 2}
};


inline static Board const optimal_board{std::array<Tile, 19>{Tile
        {5,6,3}, {5,6,4}, {5,2,8},
        {9,6,8}, {9,6,3}, {9,2,4}, {9,7,8},
        {1,6,4}, {1,6,8}, {1,2,3}, {1,7,4}, {1,7,8},
        {9,6,4}, {9,2,8}, {9,7,3}, {9,7,4}, 
        {5,2,4}, {5,7,8}, {5,7,3}
    }};

}