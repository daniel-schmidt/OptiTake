#include "OptimalSolutionPlayer.h"

#include "Board.h"

namespace OptiTake 
{

OptimalSolutionPlayer::OptimalSolutionPlayer(
    std::unique_ptr<Player> fallback_strategy_)
    : fallback_strategy(std::move(fallback_strategy_)) 
    {}

BoardPosition OptimalSolutionPlayer::SelectPosition(Tile const & chosenTile) 
{
    return optimal_board.Find(chosenTile).value_or(fallback_strategy->SelectPosition(chosenTile));
}

std::string OptimalSolutionPlayer::getName() const 
{
  return "OptimalSolutionPlayer";
}

} // namespace OptiTake