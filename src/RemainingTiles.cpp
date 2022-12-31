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
        int numberTiles = availableTiles.size() - 1;
        std::uniform_int_distribution<> distrib(0, numberTiles);

        int chosenIndex = distrib(gen);
        Tile chosenTile = availableTiles[chosenIndex];
        std::erase(availableTiles, chosenTile);
        return chosenTile;
    }
} // namespace OptiTake