#include "Board.h"
#include "RemainingTiles.h"
#include "Tile.h"
#include "Player.h"

#include <iostream>
#include <memory>

using namespace OptiTake;


int main()
{
    std::cout << "This is the game Take it Easy!\n";
    RemainingTiles remainingTiles{};
    
    std::string playerName;
    std::cout << "Enter a name: ";
    std::cin >> playerName;
    
    std::vector<std::pair<std::unique_ptr<Player>, Board>> playersWithBoard;
    playersWithBoard.emplace_back(std::make_unique<CommandLinePlayer>(playerName), Board{});
    playersWithBoard.emplace_back(std::make_unique<ComputerPlayer>(), Board{});

    
    int constexpr numBoardPositions = 19;
    for (int i = 0; i < numBoardPositions; ++i){
        // The game as a total of 27 tiles.
        // In each round, one random tile is drawn from the remaining set of tiles.
        // The tile is presented and the position is chosen by the user. 
        Tile chosenTile = remainingTiles.drawRandomTile();
        for(auto & [player, board] : playersWithBoard) {
            std::cout << "The current board of " << player->getName() << " is:\n" << board << "\n";
            player->SetChosenTile(chosenTile);
            bool success = false;
            while (!success) {
                success = board.SetTileToPosition(chosenTile, player->SelectPosition());
                if(!success) {
                    std::cout << "This is not a valid, free position. Try again!\n";
                }
            }

            std::cout << "Current score: " << board.GetScore() << "\n";
        }
    }

    for(auto & [player, board] : playersWithBoard) {
        std::cout << "The final board of " << player->getName() << " is:\n" << board << "\n";
        std::cout << "Game over! " << player->getName() << " finished with a final score of " << board.GetScore() << ".\n";
    }
}