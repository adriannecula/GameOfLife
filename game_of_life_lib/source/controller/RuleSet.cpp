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
            int16_t value = index + r * colums + c;

            if (value >= 0 && value < grid.size())
            {
                indices.push_back(value);
            }
        }
    }
    return indices;
}

bool RuleSet::willSurvive(uint16_t index)
{
    uint16_t aliveNeighbour{0};
    std::vector<uint16_t> indices = getValidNeighbourList(index);
    for (auto neighbour : indices)
    {
        if (grid[neighbour] == alive)
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
    uint16_t aliveNeighbour{0};
    std::vector<uint16_t> indices = getValidNeighbourList(index);
    for (auto neighbour : indices)
    {
        if (grid[neighbour] == alive)
        {
            ++aliveNeighbour;
        }
    }
    if (aliveNeighbour  == 3)
    {
        return true;
    }

    return false;
}



std::vector<uint8_t> RuleSet::calculate()
{    
    std::vector<uint8_t> newGrid;
    for (auto i = 0; i < grid.size(); ++i)
    {
        if (grid[i] == alive)
        {
            willSurvive(i) ?  newGrid.push_back(alive) : newGrid.push_back(dead);  
        }
        else
        {
             willCreate(i) ?  newGrid.push_back(alive) : newGrid.push_back(dead);  
        }
   
    }
    grid = newGrid;
    return grid;
}