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

TEST_F(BoardTest, check_if_we_can_set_and_get_the_field)
{
    board.setField(10);
    ASSERT_EQ(10, board.getField());
}
