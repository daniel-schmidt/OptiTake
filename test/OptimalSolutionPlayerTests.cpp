#include "OptimalSolutionPlayer.h"

#include <gmock/gmock.h>

namespace OptiTake
{

class OptimalSolutionPlayerTests : public ::testing::Test
{

};


TEST(OptimalSolutionPlayerTests, ForTileInOptimalBoard_SelectsFreePosition)
{
    OptimalSolutionPlayer under_test{};
    under_test.SetChosenTile({1,2,3});
    BoardPosition expected{2, 2};
    EXPECT_EQ(under_test.SelectPosition(), expected);
}
}