#include "OptimalSolutionPlayer.h"
#include "Player.h"

#include <gmock/gmock.h>
#include <memory>

namespace OptiTake
{

class OptimalSolutionPlayerTests : public ::testing::Test
{

};


TEST(OptimalSolutionPlayerTests, ForTileInOptimalBoard_SelectsFreePosition)
{
    auto fallback = std::make_unique<ComputerPlayer>();
    OptimalSolutionPlayer under_test{std::move(fallback)};
    under_test.SetChosenTile({1,2,3});
    BoardPosition expected{2, 2};
    EXPECT_EQ(under_test.SelectPosition(), expected);
}
}