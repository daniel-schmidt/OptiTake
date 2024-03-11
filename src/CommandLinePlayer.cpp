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
                BoardPositionOneBased position{1, 1};
                std::cin >> position;
                return position;
            } catch (std::out_of_range const &) {
                std::cout << "The position was not valid. Enter two one-based indices, i.e. 1 1 for the first tile in the first column.\n";
                // Reset failbit and remove newlines which are potentially hanging around on the stream.
                std::cin.clear();
                std::string line;
                std::getline(std::cin, line);
            }
        }
    }
    
    std::string CommandLinePlayer::getName() const 
    { 
        return name; 
    }

    } // namespace OptiTake