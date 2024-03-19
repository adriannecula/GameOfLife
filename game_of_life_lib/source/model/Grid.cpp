#include <model/Grid.hpp>

#include <iostream>

Grid::Grid(Rows rows_, Collumns collums_)
:rows{rows_},
collumns{collums_},
grid{rows*collumns, CellState::Dead}
{
}

Grid::Grid(Grid& grid_)
:rows{grid_.rows},
collumns{grid_.collumns},
grid{grid_.grid}
{
}

Grid::Grid(Grid&& grid_)
:rows{grid_.rows},
collumns{grid_.collumns},
grid{std::move(grid_.grid)}
{ 
}
bool Grid::ReviveCell(Cell cell)
{
    return setCell(cell,CellState::Alive);
}

bool Grid::KillCell(Cell cell)
{
    return setCell(cell,CellState::Dead);
}

Grid::GridElemlements Grid::getGrid()
{
    return grid;
}

bool Grid::setCell(Cell cell, CellState state)
{
    if (cell.column > collumns || cell.row > rows )
    {
        return false;
    }
    grid[rows*cell.column+cell.row] =state;
    return true;
}