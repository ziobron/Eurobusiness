#include <gtest/gtest.h>
#include "Board.hpp"

struct BoardTest : public ::testing::Test
{
    Board board;
};

TEST_F(BoardTest, check_if_getField_returns_exception_when_given_field_is_out_of_range)
{
    ASSERT_THROW(board.getField(41), std::out_of_range);
}

