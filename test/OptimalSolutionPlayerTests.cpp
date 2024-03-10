#include "Board.h"
#include "OptimalSolutionPlayer.h"
#include "RandomPlayer.h"

#include <gmock/gmock.h>
#include <memory>

namespace OptiTake
{

class OptimalSolutionPlayerTests : public ::testing::Test
{
public:
    Board board{};
};


TEST_F(OptimalSolutionPlayerTests, ForTileInOptimalBoard_SelectsFreePosition)
{
    auto fallback = std::make_unique<RandomPlayer>();
    OptimalSolutionPlayer under_test{std::move(fallback)};
    BoardPosition expected{2, 2};
    EXPECT_EQ(under_test.SelectPosition({1,2,3}, board), expected);
}
}