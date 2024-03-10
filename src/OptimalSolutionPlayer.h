#include "Player.h"
#include "Tile.h"

#include <memory>

namespace OptiTake 
{

class OptimalSolutionPlayer : public Player
{
public:
  explicit OptimalSolutionPlayer(std::unique_ptr<Player> fallback_strategy_);

  BoardPosition SelectPosition(Tile const & chosenTile, Board const & board) override;

  std::string getName() const override;

private:
  Tile current;
  std::unique_ptr<Player> fallback_strategy;
};

}