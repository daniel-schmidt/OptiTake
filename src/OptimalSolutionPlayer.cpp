#include "OptimalSolutionPlayer.h"

namespace OptiTake 
{

OptimalSolutionPlayer::OptimalSolutionPlayer(
    std::unique_ptr<Player> fallback_strategy_)
    : fallback_strategy(std::move(fallback_strategy_)) 
    {}

void OptimalSolutionPlayer::SetChosenTile(Tile const &chosenTile) 
{
    current = chosenTile;
    fallback_strategy->SetChosenTile(chosenTile);
}

BoardPosition OptimalSolutionPlayer::SelectPosition() 
{
    return optimal_board.Find(current).value_or(fallback_strategy->SelectPosition());
}

std::string OptimalSolutionPlayer::getName() const 
{
  return "OptimalSolutionPlayer";
}

} // namespace OptiTake