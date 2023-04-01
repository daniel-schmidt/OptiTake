#include "Board.h"

#include <gtest/gtest.h>

namespace OptiTake
{
class BoardTests:public::testing::Test
{
protected:
    Board under_test{};
};

TEST_F(BoardTests, SetPosition_OutsideBoardColumnTooHigh_PositionIsInvalid)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {6, 1});
    EXPECT_FALSE(success);
}

TEST_F(BoardTests, SetPosition_OutsideBoardColumnTooLow_PositionIsInvalid)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {-1, 1});
    EXPECT_FALSE(success);
}

TEST_F(BoardTests, SetPosition_OutsideBoardPosInColTooHigh_PositionIsInvalid)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {1, 5});
    EXPECT_FALSE(success);
}

TEST_F(BoardTests, SetPosition_OutsideBoardPosInColTooLow_PositionIsInvalid)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {1, -1});
    EXPECT_FALSE(success);
}

TEST_F(BoardTests, SetPosition_PosAlreadyTaken_PositionIsInvalid)
{
    bool success1 = under_test.SetTileToPosition({1, 2, 3}, {1, 1});
    ASSERT_TRUE(success1);

    bool success2 = under_test.SetTileToPosition({1, 2, 4}, {1, 1});
    EXPECT_FALSE(success2);
}





TEST_F(BoardTests, GetScore_WhenBoardIsEmpty_ScoreIsZero)
{
    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 0);
}

TEST_F(BoardTests, GetScore_WhenBoardHasSingleTile_ScoreIsZero)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {1, 1});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 0);
}





TEST_F(BoardTests, GetScore_WhenX0IsFilled_ScoreIsThree)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {0, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {0, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {0, 2});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 3);
}

TEST_F(BoardTests, GetScore_WhenX1IsFilled_ScoreIsFour)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {1, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {1, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {1, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 3}, {1, 3});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 4);
}

TEST_F(BoardTests, GetScore_WhenX2IsFilled_ScoreIsFive)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {2, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {2, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {2, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 3}, {2, 3});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 4}, {2, 4});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 5);
}

TEST_F(BoardTests, GetScore_WhenX3IsFilled_ScoreIsFour)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {3, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {3, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {3, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 3}, {3, 3});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 4);
}

TEST_F(BoardTests, GetScore_WhenX4IsFilled_ScoreIsThree)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {4, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {4, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {4, 2});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 3);
}





TEST_F(BoardTests, GetScore_WhenY0IsFilled_ScoreIsSix)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {0, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {1, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {2, 0});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 6);
}

TEST_F(BoardTests, GetScore_WhenY1IsFilled_ScoreIsEight)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {0, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {1, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {2, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({5, 2, 3}, {3, 0});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 8);
}

TEST_F(BoardTests, GetScore_WhenY2IsFilled_ScoreIsTen)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {0, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {1, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {2, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({5, 2, 3}, {3, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({5, 2, 4}, {4, 0});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 10);
}

TEST_F(BoardTests, GetScore_WhenY3IsFilled_ScoreIsEight)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {1, 3});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {2, 3});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {3, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({5, 2, 3}, {4, 1});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 8);
}

TEST_F(BoardTests, GetScore_WhenY4IsFilled_ScoreIsSix)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {2, 4});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 4}, {3, 3});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 2, 8}, {4, 2});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 6);
}




TEST_F(BoardTests, GetScore_WhenZ0IsFilled_ScoreIsNine)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {0, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 3}, {1, 3});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 7, 3}, {2, 4});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 9);
}

TEST_F(BoardTests, GetScore_WhenZ1IsFilled_ScoreIsTwelfe)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {0, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 3}, {1, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 7, 3}, {2, 3});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({5, 2, 3}, {3, 3});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 12);
}

TEST_F(BoardTests, GetScore_WhenZ2IsFilled_ScoreIsFifteen)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {0, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 3}, {1, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 7, 3}, {2, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({5, 2, 3}, {3, 2});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({5, 6, 3}, {4, 2});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 15);
}

TEST_F(BoardTests, GetScore_WhenZ3IsFilled_ScoreIsTwelfe)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {1, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 3}, {2, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 7, 3}, {3, 1});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({5, 2, 3}, {4, 1});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 12);
}

TEST_F(BoardTests, GetScore_WhenZ4IsFilled_ScoreIsNine)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {2, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 6, 3}, {3, 0});
    ASSERT_TRUE(success);
    success = under_test.SetTileToPosition({1, 7, 3}, {4, 0});
    ASSERT_TRUE(success);

    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 9);
}


TEST_F(BoardTests, GetScore_OfOptimalBoard_ScoreIs307)
{
    under_test = optimal_board;
    auto const result = under_test.GetScore();
    EXPECT_EQ(result, 307);
}

}