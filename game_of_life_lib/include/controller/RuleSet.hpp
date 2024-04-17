#pragma once

#include <vector>
#include <cstdint>
#include <functional>
#include <model/Grid.hpp>
class RuleSet
{
public:
    RuleSet()
    :grid{1,1}
    {
       
    }
    RuleSet(Grid grid_)
        : grid{grid_}, iterations{0}, isStable{false}
    {
    }
    bool willSurvive(uint16_t index);
    bool willCreate(uint16_t index);

    Grid calculate();
    inline bool isAlive(uint16_t cellValue)
    {
        return cellValue == 1;
    }
    inline uint64_t getIterations()
    {
        return iterations;
    }
    inline void resetIterations()
    {
        iterations = 0;
    }
    inline void setGrid(Grid grid_)
    {
        grid = grid_;
    }
    inline bool isGridStable()
    {
        return isStable;
    }

private:
    std::vector<uint16_t> getValidNeighbourList(const uint16_t index) const;
    Grid grid;
    uint64_t iterations;
    bool isStable;
    //bool isPeriodicallyBounded;
   // std::function<std::vector<uint16_t>(const RuleSet&, u_int16_t) >getNeighbours;
};