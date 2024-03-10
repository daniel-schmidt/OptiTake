#pragma once
#include "Player.h"

#include <random>

namespace OptiTake 
{
    class RandomPlayer : public Player
    {
    public:
        BoardPosition SelectPosition(Tile const & chosenTile, Board const & board) override;

        std::string getName() const override;

      private:
        // to draw a random position for column
        std::random_device rdPos;
        std::default_random_engine genPos{rdPos()};
    };
}