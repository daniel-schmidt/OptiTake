#include "Board.h"
#include "RemainingTiles.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ostream>
#include <random>
#include <string>
#include <vector>

using namespace OptiTake;

int main()
{
    std::cout << "This is the game Take it Easy!" << std::endl;
    RemainingTiles remainingTiles{};
    Board board{};
    
    for (int i = 0; i < 19; ++i){
        std::cout << "The current board is:\n" << board << "\n";
        Tile chosenTile = remainingTiles.drawRandomTile();
        std::cout << "The chosen tile is " << chosenTile << ".\n";
        
        bool success = false;
        while (!success) {
            std::cout << "Please insert a position: ";
            int colIndex = 0;
            std::cin >> colIndex;
            int posInCol = 0;
            std::cin >> posInCol;
            success = board.SetTileToPosition(chosenTile, {colIndex, posInCol});
            if(!success) {
                std::cout << "This is not a valid, free position. Try again!\n";
            }
        }
    }
    std::cout << "Game over!" << std::endl;
}