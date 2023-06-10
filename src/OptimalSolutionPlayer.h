#include "Player.h"

#include <memory>

namespace OptiTake 
{

class OptimalSolutionPlayer : public Player
{
public:
  explicit OptimalSolutionPlayer(std::unique_ptr<Player> fallback_strategy_);
  void SetChosenTile(Tile const &chosenTile) override;

  BoardPosition SelectPosition() override;

  std::string getName() const override;

private:
  Tile current;
  std::unique_ptr<Player> fallback_strategy;
};

}