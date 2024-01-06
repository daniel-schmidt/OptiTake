#include "Board.h"
#include "OptimalSolutionPlayer.h"
#include "RandomPlayer.h"

#include <gmock/gmock.h>
#include <memory>

namespace OptiTake
{

class OptimalSolutionPlayerTests : public ::testing::Test
{

};


TEST(OptimalSolutionPlayerTests, ForTileInOptimalBoard_SelectsFreePosition)
{
    auto fallback = std::make_unique<RandomPlayer>();
    OptimalSolutionPlayer under_test{std::move(fallback)};
    under_test.SetChosenTile({1,2,3});
    BoardPosition expected{2, 2};
    EXPECT_EQ(under_test.SelectPosition(), expected);
}
}