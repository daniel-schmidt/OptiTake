#include "Board.h"

#include <gtest/gtest.h>

namespace OptiTake
{

TEST(BoardTests, GetScore_WhenBoardIsEmpty_ScoreIsZero)
{
    Board under_test{};
    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 0);
}

TEST(BoardTests, GetScore_WhenBoardHasSingleTile_ScoreIsZero)
{
    Board under_test{};
    bool success = under_test.SetTileToPosition({1, 2, 3}, {1, 1});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 0);
}

}