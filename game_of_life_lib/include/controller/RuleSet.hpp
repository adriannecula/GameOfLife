#pragma once

#include <vector>
#include <cstdint>
#include <model/Grid.hpp>
class RuleSet
{
public:
    RuleSet(Grid grid_)
        : grid{grid_}
    {
    }
    bool willSurvive(uint16_t index);
    bool willCreate(uint16_t index);
    Grid calculate();
    inline bool isAlive(uint16_t cellValue)
    {
        return cellValue == 1;
    }

private:
    std::vector<uint16_t> getValidNeighbourList(const uint16_t index) const;
    Grid grid;
};