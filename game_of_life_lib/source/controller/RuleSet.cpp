#include <controller/RuleSet.hpp>
// Find the number of valid neighbours for this cell
//   x x x
//   x o x
//   x x x

std::vector<uint16_t> RuleSet::getValidNeighbourList(const uint16_t index) const
{
    Grid::Collumn collumCount = grid.getColumnsSize();
    int16_t rowCount = grid.getArray().size() / collumCount;
    int16_t cellRow = index / collumCount;
    int16_t cellColum = index % collumCount;

    std::vector<uint16_t> neighbours;

    for (auto row = -1; row < 2; ++row)
    {
        for (auto column = -1; column < 2; ++column)
        {
            if (row == 0 && column == 0)
            {
                continue;
            }

            int16_t neighbourRow = cellRow - row;
            int16_t neighbourColumn = cellColum - column;
            if (neighbourRow == -1)
            {
                neighbourRow = rowCount - 1;
            }
            else if (neighbourRow >= rowCount)
            {
                neighbourRow = 0;
            }
            if (neighbourColumn == -1)
            {
                neighbourColumn = collumCount - 1;
            }

            else if (neighbourColumn >= collumCount)
            {
                neighbourColumn = 0;
            }
            
            int16_t neighbourIndex = neighbourRow * grid.getColumnsSize() + neighbourColumn;

            neighbours.push_back(neighbourIndex);
        }
    }

    // for (auto row = -1; row < 2; ++row)
    // {
    //     for (auto column = -1; column < 2; ++column)
    //     {
    //         if (row == 0 && column == 0)
    //         {
    //             continue;
    //         }
    //         int16_t neighbourIndex = index + row * grid.getColumnsSize() + column;

    //         if (neighbourIndex >= 0 && neighbourIndex < grid.getArray().size())
    //         {
    //           break;
    //         }
    //     }
    // }
    return neighbours;
}

bool RuleSet::willSurvive(uint16_t index)
{
    const uint16_t underpopulationLimmit = 2;
    const uint16_t overpopulationLimmit = 3;

    auto values = grid.getArray();
    uint16_t aliveNeighbour{0};
    std::vector<uint16_t> indices = getValidNeighbourList(index);
    for (auto neighbour : indices)
    {
        if (values[neighbour] == Grid::CellState::Alive)
        {
            ++aliveNeighbour;
        }
    }
    if (aliveNeighbour < underpopulationLimmit || aliveNeighbour > overpopulationLimmit)
    {
        return false;
    }

    return true;
}

bool RuleSet::willCreate(uint16_t index)
{
    auto values = grid.getArray();
    uint16_t aliveNeighbour{0};
    std::vector<uint16_t> indices = getValidNeighbourList(index);
    for (auto neighbour : indices)
    {
        if (values[neighbour] == Grid::CellState::Alive)
        {
            ++aliveNeighbour;
        }
    }
    if (aliveNeighbour == 3)
    {
        return true;
    }

    return false;
}

Grid RuleSet::calculate()
{

    isStable = false;
    auto values = grid.getArray();
    ++iterations;

    Grid newGrid{grid};
    auto &newValues = newGrid.getArray();
    for (auto i = 0; i < values.size(); ++i)
    {
        if (values[i] == Grid::CellState::Alive)
        {
            newValues[i] = willSurvive(i) ? Grid::CellState::Alive : Grid::CellState::Dead;
        }
        else
        {
            newValues[i] = willCreate(i) ? Grid::CellState::Alive : Grid::CellState::Dead;
        }
    }

    if (newGrid == grid)
    {
        isStable = true;
    }
    grid = newGrid;

    return grid;
}
