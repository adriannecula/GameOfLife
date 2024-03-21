#pragma once
#include <model/Grid.hpp>

namespace helpers
{
  class TestGrids  
  {
    public:
    const Grid::Row defaultRowsSize = 5;
    const Grid::Collumn defaultColumnSize = 5;
    enum class Patterns
    {
        dead_inside,
        dies_1,
        dies_2_line_horisontal,
        osclilator_3_line_horizontal,
        osclilator_3_line_vertical,
        still_4_block
    };
    Grid getStandardGrid(Patterns pattern);
 };
}