#pragma once

#include <vector>
#include <cstdint>
class RuleSet
{
public:
    const uint8_t alive = 1;
    const uint8_t dead = 0;
    const uint16_t underpopulationLimmit =2;
    const uint16_t overpopulationLimmit = 3; 
     RuleSet(std::pair<std::vector<uint8_t>,uint16_t> grid_ )
     :grid{grid_.first}, colums(grid_.second)
     {

     }
    bool willSurvive(uint16_t index);
    bool willCreate(uint16_t index);
    std::vector<uint8_t> calculate();
    inline bool isAlive(uint16_t cellValue)
    {   
        return cellValue == 1;
    }

private:
    std::vector<uint16_t> getValidNeighbourList(const uint16_t index) const;
    std::vector<uint8_t> grid;
   
    uint16_t colums;
};