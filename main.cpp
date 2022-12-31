#include "src/RemainingTiles.h"

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
    for (int i = 0; i < 19; ++i){
        Tile chosenTile = remainingTiles.drawRandomTile();
        std::cout << "The chosen tile is " << chosenTile << ".\n";
    }
    std::cout << "Game over!" << std::endl;
}