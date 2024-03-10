#include "CommandLinePlayer.h"

#include "Board.h"
#include "Tile.h"

#include <iostream>

namespace OptiTake
{    
    CommandLinePlayer::CommandLinePlayer(std::string playerName)
        : name{std::move(playerName)} 
        {

        }

    BoardPosition CommandLinePlayer::SelectPosition(Tile const & chosenTile)
    {
        std::cout << "The chosen tile is:\n" << chosenTile << "\n";
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

    } // namespace OptiTake