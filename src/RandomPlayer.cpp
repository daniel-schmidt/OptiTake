#include "RandomPlayer.h"

#include "Board.h"

namespace OptiTake 
{
    BoardPosition RandomPlayer::SelectPosition(Tile const & chosenTile)
    {
        // each position has the same probability to be drawn,
        int numPositions = allPossiblePositions.size() - 1;
        std::uniform_int_distribution distrib(0, numPositions);

        // draw a random number between 0 and the number of available tiles 
        int const positionIndex = distrib(genPos);
        auto const [colIndex, posInCol] = allPossiblePositions[positionIndex];

        // The input should be 1 based for easier understanding. The colIndex and posInCol are 0 based.
        return {colIndex-1, posInCol-1};
    }

    std::string RandomPlayer::getName() const 
    { 
        return "Random Player"; 
    }
}