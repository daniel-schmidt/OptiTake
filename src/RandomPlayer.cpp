#include "RandomPlayer.h"

#include "Board.h"

namespace OptiTake 
{
    BoardPosition RandomPlayer::SelectPosition(Tile const & chosenTile, Board const & board)
    {
        // Each of the remaining free positions has the same probability to be drawn.
        auto const free_positions = board.GetFreePositions();
        auto const num_positions = static_cast<int>(free_positions.size()) - 1;
        std::uniform_int_distribution distrib(0, num_positions);

        // Draw a random number between 0 and the number of available tiles.
        return free_positions[distrib(genPos)];
    }

    std::string RandomPlayer::getName() const 
    { 
        return "Random Player"; 
    }
}