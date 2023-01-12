#include "Player.h"

#include <chrono>
#include <thread>

namespace OptiTake
{
    void CommandLinePlayer::SetChosenTile(Tile const & chosenTile)
    {
        std::cout << "The chosen tile is:\n" << chosenTile << "\n";
    }

    BoardPosition CommandLinePlayer::GetPosition() const
    {
        std::cout << "Please insert a position (format: column row): ";
        int colIndex = 0;
        int posInCol = 0;
        std::cin >> colIndex >> posInCol;
        // The input should be 1 based for easier understanding. The colIndex and posInCol are 0 based.
        return {colIndex-1, posInCol-1};
    }


    void ComputerPlayer::SetChosenTile(Tile const & chosenTile)
    {
        std::cout << "The chosen tile is:\n" << chosenTile << "\n";

        std::chrono::milliseconds timespan(2000);
        std::this_thread::sleep_for(timespan);
    }

    BoardPosition ComputerPlayer::GetPosition() const
    {
        // each position has the same probability to be drawn
        int numPositions = 5;
        std::uniform_int_distribution<> distrib(1, numPositions);

        // draw a random number between 0 and the number of available tiles 
        int colIndex = distrib(gen_pos);
        int posInCol = distrib(gen_pos);

        std::cout << "The chosen position is: " << colIndex << ", " << posInCol << "\n";

        // The input should be 1 based for easier understanding. The colIndex and posInCol are 0 based.
        return {colIndex-1, posInCol-1};
    }
}