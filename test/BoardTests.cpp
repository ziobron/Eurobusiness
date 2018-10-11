#include <gtest/gtest.h>
#include "Board.hpp"

struct BoardTest : public ::testing::Test
{
    Board board;
};

TEST_F(BoardTest, check_if_board_contains_40_fields)
{
    ASSERT_EQ(40, board.getNumberOfFields());
}

