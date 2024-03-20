#include <vector>
#include <utility>
#include <iostream>
#include <controller/RuleSet.hpp>
#include <TestGrids.hpp>
#include <gtest/gtest.h>

class RuleSetTests : public testing::Test
{
};

TEST_F(RuleSetTests, MyTest)
{
    auto grid = helpers::getStandardGrid();
    RuleSet game{grid};
    game.calculate();
    std::cout << "it's alive\n";
    ASSERT_EQ(2 + 2, 4);
}
