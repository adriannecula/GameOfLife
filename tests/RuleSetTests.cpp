#include <vector>
#include <utility>
#include <iostream>
#include <controller/RuleSet.hpp>
#include <TestGrids.hpp>
#include <gtest/gtest.h>

using namespace helpers;
struct TestParam
{
TestGrids::Patterns input;
TestGrids::Patterns result;
};

class RuleSetTests : public testing::TestWithParam<TestParam>
{
public:   
    RuleSetTests()
    :grids{}
    {    
    }

helpers::TestGrids grids;

};

constexpr TestParam values[] ={
{TestGrids::Patterns::dies_1,TestGrids::Patterns::dead_inside},
{TestGrids::Patterns::dies_2_line_horisontal,TestGrids::Patterns::dead_inside},
{TestGrids::Patterns::osclilator_3_line_horizontal, TestGrids::Patterns::osclilator_3_line_vertical},
{TestGrids::Patterns::osclilator_3_line_vertical, TestGrids::Patterns::osclilator_3_line_vertical},
{TestGrids::Patterns::still_4_block, TestGrids::Patterns::still_4_block},
{TestGrids::Patterns::spaceship_5_glider_laydown_L, TestGrids::Patterns::spaceship_5_glider_up_Z}};

INSTANTIATE_TEST_SUITE_P(InstantiationName, RuleSetTests, testing::ValuesIn(values));
TEST_P(RuleSetTests, TestCellRules)
{
    auto grid = grids.getStandardGrid(helpers::TestGrids::Patterns::dies_1);
    RuleSet rules{grid};
    
    auto result = rules.calculate();
    auto expectedValue = grids.getStandardGrid(helpers::TestGrids::Patterns::dead_inside);
    ASSERT_EQ(expectedValue.getArray(), result.getArray());
}



