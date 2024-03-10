#pragma once
#include "Player.h"

namespace OptiTake
{
    class CommandLinePlayer : public Player
    {
    public:
      explicit CommandLinePlayer(std::string playerName);

      BoardPosition SelectPosition(Tile const & chosenTile) override;

      std::string getName() const override;

    private:
      std::string name;
    };
}