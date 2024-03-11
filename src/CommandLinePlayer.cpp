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

    BoardPosition CommandLinePlayer::SelectPosition(Tile const & chosenTile, Board const & board)
    {
        std::cout << "The chosen tile is:\n" << chosenTile << "\n";
        while (true) {
            try {
                std::cout << "Please insert a position (format: column row): ";
                int colIndex = 0;
                int posInCol = 0;
                std::cin >> colIndex >> posInCol;
                BoardPositionOneBased position{colIndex, posInCol};
                return position;
            } catch (std::out_of_range const &) {
                std::cout << "The position was not valid. Enter two one-based indices, i.e. 1, 1 for the first tile in the first column.\n";
            }
        }
    }
    
    std::string CommandLinePlayer::getName() const 
    { 
        return name; 
    }

    } // namespace OptiTake