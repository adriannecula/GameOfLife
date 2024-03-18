#include <vector>
#include <utility>
#include <iostream>
#include <controller/RuleSet.hpp>
#include <TestGrids.hpp>

#include <gtest/gtest.h>
TEST(Example, MyTest)
{
    std::pair<std::vector<uint8_t>,uint16_t> grid = helpers::getStandardGrid();
    RuleSet game{grid};
    game.calculate();
    std::cout<<"it's alive\n";
    ASSERT_EQ(2+2,4);

}


