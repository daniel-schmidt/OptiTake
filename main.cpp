#include "Board.h"
#include "RemainingTiles.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <ostream>
#include <random>
#include <string>
#include <vector>

using namespace OptiTake;

int main()
{
    std::cout << "This is the game Take it Easy!\n";
    RemainingTiles remainingTiles{};
    Board board{};
    
    for (int i = 0; i < 19; ++i){
        std::cout << "The current board is:\n" << board << "\n";
        Tile chosenTile = remainingTiles.drawRandomTile();
        std::cout << "The chosen tile is " << chosenTile << ".\n";
        
        bool success = false;
        while (!success) {
            std::cout << "Please insert a position (format: column row): ";
            int colIndex = 0;
            int posInCol = 0;
            std::cin >> colIndex >> posInCol;
            success = board.SetTileToPosition(chosenTile, {colIndex, posInCol});
            if(!success) {
                std::cout << "This is not a valid, free position. Try again!\n";
            }
        }

        std::cout << "Current score: " << board.GetScore() << "\n";
    }
    std::cout << "The final board is:\n" << board << "\n";
    std::cout << "Game over! You finished with a final score of " << board.GetScore() << ".\n";
}