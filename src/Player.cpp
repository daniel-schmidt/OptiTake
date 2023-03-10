#include "Player.h"

#include <chrono>
#include <thread>

namespace OptiTake
{    
    CommandLinePlayer::CommandLinePlayer(std::string playerName)
        : name{playerName} 
        {

        }

    void CommandLinePlayer::SetChosenTile(Tile const & chosenTile)
    {
        std::cout << "The chosen tile is:\n" << chosenTile << "\n";
    }

    BoardPosition CommandLinePlayer::SelectPosition()
    {
        std::cout << "Please insert a position (format: column row): ";
        int colIndex = 0;
        int posInCol = 0;
        std::cin >> colIndex >> posInCol;
        // The input should be 1 based for easier understanding. The colIndex and posInCol are 0 based.
        return {colIndex-1, posInCol-1};
    }
    
    std::string CommandLinePlayer::getName() const 
    { 
        return name; 
    }


    void ComputerPlayer::SetChosenTile(Tile const & chosenTile)
    {
        std::cout << "The chosen tile is:\n" << chosenTile << "\n";

        std::chrono::milliseconds timespan(2000);
        std::this_thread::sleep_for(timespan);
    }

    BoardPosition ComputerPlayer::SelectPosition()
    {
        // each position has the same probability to be drawn,
        int numPositions = allPossiblePositions.size() - 1;
        std::uniform_int_distribution<> distrib(0, numPositions);

        // draw a random number between 0 and the number of available tiles 
        int const positionIndex = distrib(genPos);
        auto const [colIndex, posInCol] = allPossiblePositions[positionIndex];
        std::cout << "The chosen position is: " << colIndex << ", " << posInCol << "\n";

        // The input should be 1 based for easier understanding. The colIndex and posInCol are 0 based.
        return {colIndex-1, posInCol-1};
    }

    std::string ComputerPlayer::getName() const 
    { 
        return "Computer Player"; 
    }

    } // namespace OptiTake