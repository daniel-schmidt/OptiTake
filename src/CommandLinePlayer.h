#pragma once
#include "Player.h"

namespace OptiTake
{
    class CommandLinePlayer : public Player
    {
    public:
      CommandLinePlayer(std::string playerName);

      void SetChosenTile(Tile const &chosenTile) override;

      BoardPosition SelectPosition() override;

      std::string getName() const override;

    private:
      std::string name;
    };
}