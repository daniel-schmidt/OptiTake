#include "OptimalSolutionPlayer.h"

#include "Board.h"

namespace OptiTake 
{

OptimalSolutionPlayer::OptimalSolutionPlayer(
    std::unique_ptr<Player> fallback_strategy_)
    : fallback_strategy(std::move(fallback_strategy_)) 
    {}

BoardPosition OptimalSolutionPlayer::SelectPosition(Tile const & chosenTile, Board const & board) 
{
    if (auto selected = optimal_board.Find(chosenTile); selected && board.IsFree(*selected)) {
      return *selected;
    }
    return fallback_strategy->SelectPosition(chosenTile, board);
}

std::string OptimalSolutionPlayer::getName() const 
{
  return "OptimalSolutionPlayer";
}

} // namespace OptiTake