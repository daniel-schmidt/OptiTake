#include "Player.h"

namespace OptiTake 
{

class OptimalSolutionPlayer : public Player
{
public:
  void SetChosenTile(Tile const &chosenTile) override;

  BoardPosition SelectPosition() override;

  std::string getName() const override;

private:
  Tile current;
};

}