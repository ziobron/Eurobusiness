#include <gtest/gtest.h>
#include "Board.hpp"
#include "Field.hpp"

struct BoardTest : public ::testing::Test
{
    Board board;
};

TEST_F(BoardTest, check_if_factoryFields_made_property_Madrit)
{
    std::shared_ptr<Field> madrit = board.factoryFields("Espania - Mardit");
    ASSERT_EQ("Madrit", madrit->getName());
}

