#include "OptimalSolutionPlayer.h"

namespace OptiTake 
{

void OptimalSolutionPlayer::SetChosenTile(Tile const &chosenTile) 
{
    current = chosenTile;
}

BoardPosition OptimalSolutionPlayer::SelectPosition() 
{
    return optimal_board.Find(current).value_or(BoardPosition{-1,-1});
}

std::string OptimalSolutionPlayer::getName() const 
{
  return "OptimalSolutionPlayer";
}

} // namespace OptiTake