#include <controller/RuleSet.hpp>

// Find the number of valid neighbours for this cell
//   x x x
//   x o x
//   x x x
std::vector<uint16_t> RuleSet::getValidNeighbourList(const uint16_t index) const
{
    std::vector<uint16_t> indices;
    for (auto r = -1; r < 2; ++r)
    {
        for (auto c = -1; c < 2; ++c)
        {
            if (r == 0 && c == 0)
            {
                continue;
            }
            int16_t value = index + r * grid.getColumnsSize() + c;

            if (value >= 0 && value < grid.getValues().size())
            {
                indices.push_back(value);
            }
        }
    }
    return indices;
}

bool RuleSet::willSurvive(uint16_t index)
{
    const uint16_t underpopulationLimmit = 2;
    const uint16_t overpopulationLimmit = 3;

    auto values = grid.getValues();
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
    auto values = grid.getValues();
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
    auto values = grid.getValues();
    ++iterations;
    Grid newGrid{grid};
    auto &newValues = newGrid.getValues();
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

    if(newGrid == grid)
    {
        isStable = true;   
    }
    grid = newGrid;

    return grid;
}