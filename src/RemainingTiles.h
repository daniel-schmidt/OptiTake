#pragma once
#include "Tile.h"

#include <vector>
#include <random>


namespace OptiTake 
{
    class RemainingTiles 
    {
    public:
        RemainingTiles();

        Tile drawRandomTile();

    private:
        std::vector<Tile> availableTiles{};
        // to draw a random tile from the available tiles
        std::random_device rd;
        std::default_random_engine gen{rd()};
    };
}