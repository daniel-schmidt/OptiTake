#include "Board.h"

#include <gmock/gmock.h>
#include <stdexcept>

namespace OptiTake 
{
using ::testing::Optional;

class BoardTests:public::testing::Test
{
public:
    Board under_test{};
};

TEST_F(BoardTests, BoardPosition_WhenConstructedWithIndexTooLow_Throws)
{
    EXPECT_THROW(BoardPosition(-1, 1), std::out_of_range);
    EXPECT_THROW(BoardPosition(1, -1), std::out_of_range);
    EXPECT_THROW(BoardPositionOneBased(1, 0), std::out_of_range);
    EXPECT_THROW(BoardPositionOneBased(0, 1), std::out_of_range);
}

TEST_F(BoardTests, BoardPosition_WhenConstructedWithMinimalIndex_IsValid)
{
    BoardPosition under_test(0, 0);
    EXPECT_EQ(under_test.GetColIndex(), 0);
    EXPECT_EQ(under_test.GetPosInCol(), 0);
    
    BoardPositionOneBased under_test_1(1, 1);
    EXPECT_EQ(under_test_1.GetColIndex(), 1);
    EXPECT_EQ(under_test_1.GetPosInCol(), 1);
}

TEST_F(BoardTests, BoardPositionOneBased_FromZeroBased_AddsOne)
{
    BoardPosition input{0, 0};
    BoardPositionOneBased under_test = input;

    EXPECT_EQ(under_test.GetColIndex(), 1);
    EXPECT_EQ(under_test.GetPosInCol(), 1);
}

TEST_F(BoardTests, SetPosition_OutsideBoardColumnTooHigh_PositionIsInvalid)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {6, 1});
    EXPECT_FALSE(success);
}

TEST_F(BoardTests, SetPosition_OutsideBoardPosInColTooHigh_PositionIsInvalid)
{
    bool success = under_test.SetTileToPosition({1, 2, 3}, {1, 5});
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


TEST_F(BoardTests, Find_WithPieceNotInOptimalBoard_ReturnsEmptyOptional)
{
    under_test = optimal_board;
    EXPECT_EQ(under_test.Find({1,2,4}), std::nullopt);
}

TEST_F(BoardTests, Find_WithPieceOfOptimalBoard_ReturnsPosition)
{
    under_test = optimal_board;
    EXPECT_THAT(under_test.Find({5,6,3}), Optional(BoardPosition{0, 0}));
    EXPECT_THAT(under_test.Find({1,2,3}), Optional(BoardPosition{2, 2}));
    EXPECT_THAT(under_test.Find({5,7,8}), Optional(BoardPosition{4, 1}));
}

TEST_F(BoardTests, GetFreePositions_WithEmptyBoard_ReturnsAllPositions)
{
    under_test = Board{};
    EXPECT_THAT(under_test.GetFreePositions(), testing::ElementsAreArray(allPossiblePositions));
}

TEST_F(BoardTests, GetFreePositions_WithOptimalBoard_ReturnsEmptyContainer)
{
    under_test = optimal_board;
    EXPECT_THAT(under_test.GetFreePositions(), testing::IsEmpty());
}

} // namespace OptiTake