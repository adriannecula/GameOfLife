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
      values{grid_.values}
{
}

Grid::Grid(Grid &&grid_)
    : rows{grid_.rows},
      collumns{grid_.collumns},
    values{std::move(grid_.values)}
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
    return values;
}

Grid::Values &Grid::getValues()
{
    return values;
}
bool Grid::setCell(Cell cell, CellState state)
{
    if (cell.collumn > collumns || cell.row > rows)
    {
        return false;
    }
    values[rows * cell.collumn + cell.row] = state;
    return true;
}


bool Grid::operator==(const Grid& rhs)
{
    return (values == rhs.values && collumns == rhs.collumns);
}