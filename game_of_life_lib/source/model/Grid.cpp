#include <model/Grid.hpp>

#include <iostream>

Grid::Grid(Rows rows_, Collumns collums_)
    : rows{rows_},
      collumns{collums_}
{
}

Grid::Grid(Grid &grid_)
    : rows{grid_.rows},
      collumns{grid_.collumns},
      grid{grid_.grid}
{
}

Grid::Grid(Grid &&grid_)
    : rows{grid_.rows},
      collumns{grid_.collumns},
      grid{std::move(grid_.grid)}
{
}
bool Grid::ReviveCell(Cell cell)
{
    return setCell(cell, CellState::Alive);
}

Grid::Collumns Grid::getColumnsSize() const
{
    return collumns;
}

bool Grid::KillCell(Cell cell)
{
    return setCell(cell, CellState::Dead);
}

const Grid::Values &Grid::getValues() const
{
    return grid;
}

Grid::Values &Grid::getValues()
{
    return grid;
}
bool Grid::setCell(Cell cell, CellState state)
{
    if (cell.collumn > collumns || cell.row > rows)
    {
        return false;
    }
    grid[rows * cell.collumn + cell.row] = state;
    return true;
}


bool Grid::operator==(const Grid& rhs)
{
    return (grid == rhs.grid && collumns == rhs.collumns);
}