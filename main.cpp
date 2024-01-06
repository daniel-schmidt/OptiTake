#include "Board.h"
#include "CommandLinePlayer.h"
#include "OptimalSolutionPlayer.h"
#include "RandomPlayer.h"
#include "RemainingTiles.h"
#include "Tile.h"

#include <iostream>
#include <memory>
#include <algorithm>

using namespace OptiTake;


int main()
{
    std::cout << "This is the game Take it Easy!\n";
    RemainingTiles remainingTiles{};
    
    int numberOfPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numberOfPlayers;

    std::vector<std::pair<std::unique_ptr<Player>, Board>> playersWithBoard;
    for (int i = 0; i < numberOfPlayers; ++i){
        std::string playerName;
        std::cout << "Enter a name: ";
        std::cin >> playerName;
        playersWithBoard.emplace_back(std::make_unique<CommandLinePlayer>(std::move(playerName)), Board{});
    }
    auto fallback = std::make_unique<RandomPlayer>();
    playersWithBoard.emplace_back(std::make_unique<OptimalSolutionPlayer>(std::move(fallback)), Board{});
    
    int constexpr numBoardPositions = 19;
    for (int i = 0; i < numBoardPositions; ++i){
        // The game as a total of 27 tiles.
        // In each round, one random tile is drawn from the remaining set of tiles.
        // The tile is presented and the position is chosen by the user. 
        Tile chosenTile = remainingTiles.drawRandomTile();
        for(auto & [player, board] : playersWithBoard) {
            std::cout << "---------------------\n";
            std::cout << "The current board of " << player->getName() 
                      << " with the score of " << board.GetScore() 
                      << " is:\n" << board << "\n";
            player->SetChosenTile(chosenTile);
            bool success = false;
            while (!success) {
                success = board.SetTileToPosition(chosenTile, player->SelectPosition());
                if(!success) {
                    std::cout << "This is not a valid, free position. Try again!\n";
                }
            }
        }
    }

    std::cout << "\n\n***GAME OVER***\n";
    std::vector<int> finalScores;
    for(auto & [player, board] : playersWithBoard) {
        finalScores.emplace_back(board.GetScore());
        std::cout << player->getName() 
                  << " finished with a final score of " 
                  << board.GetScore() << " with the board: \n" << board << "\n";
    }

    std::vector<int>::const_iterator bestPlayer = std::max_element(finalScores.begin(), finalScores.end());
    std::cout << "***The player "
              << playersWithBoard.at(std::distance(finalScores.cbegin(), bestPlayer)).first->getName()
              << " wins with the score of " << *bestPlayer << "!***\n";
}