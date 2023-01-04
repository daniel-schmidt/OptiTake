#include "RemainingTiles.h"

#include <algorithm>
#include <cassert>

namespace OptiTake
{
    RemainingTiles::RemainingTiles()
    { 
        std::ranges::copy(allPossibleTiles, std::back_inserter(availableTiles)); 
    }

    Tile RemainingTiles::drawRandomTile() 
    {
        assert(!availableTiles.empty());
        if (availableTiles.size() == 1) {
        return availableTiles[0];
        }
        // each tile has the same probability to be drawn
        int numberTiles = availableTiles.size() - 1;
        std::uniform_int_distribution<> distrib(0, numberTiles);

        // draw a random number between 0 and the number of available tiles 
        int chosenIndex = distrib(gen);
        // use this number as index to chose a tile from the available tiles
        Tile chosenTile = availableTiles[chosenIndex];
        // erase the chosen tile from the available tiles. Tiles can only be drawn once.
        std::erase(availableTiles, chosenTile);
        return chosenTile;
    }
} // namespace OptiTake