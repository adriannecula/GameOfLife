
#include <vector>
#include <utility>
#include <cstdint>
#include "TestGrids.hpp"
namespace helpers
{   
    /*  
        00 01 02 03 04
        05 06 07 08 09
        10 11 12 13 14
        15 16 17 18 19
        20 21 22 23 24 
    */  

      Grid TestGrids::getStandardGrid(Patterns pattern)
      {
        Grid::Array array{defaultRowsSize*defaultColumnSize, Grid::CellState::Dead};
        switch (pattern)
        {
        case Patterns::dead_inside:
            break;
        case Patterns::dies_1:
        
            array[12] = Grid::CellState::Alive;
            break;
        case Patterns::dies_2_line_horisontal:
            array[12] = Grid::CellState::Alive;
            array[17] = Grid::CellState::Alive;
            break;
        case Patterns::osclilator_3_line_horizontal:
            array[07] = Grid::CellState::Alive; 
            array[12] = Grid::CellState::Alive;
            array[17] = Grid::CellState::Alive;
            break;   
        default:
            break;
        }
        return {defaultRowsSize,defaultColumnSize, array};
      }

   

}
