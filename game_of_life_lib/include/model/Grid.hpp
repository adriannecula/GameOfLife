#pragma once

#include <cstdint>
#include <vector>


class Grid
{
public:
    using Rows = uint64_t;
    using Collumns = uint64_t;
    using Row = uint64_t;
    using Column = uint64_t;
        enum  class CellState: uint8_t{
        Alive,
        Dead
    };
    using GridElemlements = std::vector<CellState>;
    struct Cell
    {
        Row row;
        Column column;
    };

   
    Grid(Rows row_, Collumns collum_);
    Grid(Grid& grid_);
    Grid(Grid&& grid_);
    bool ReviveCell(Cell cell);
    bool KillCell(Cell cell);
    GridElemlements getGrid();
private: 
    bool setCell(Cell cell, CellState state);
    Rows rows;
    Collumns collumns;
    GridElemlements grid;
   
    


};
