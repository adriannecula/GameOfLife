#pragma once
#include <cstdint>
#include <vector>

class Grid
{
public:
    using Rows = uint64_t;
    using Collumns = uint64_t;
    using Row = uint64_t;
    using Collumn = uint64_t;
    enum class CellState : uint8_t
    {
        Alive,
        Dead
    };
    using Values = std::vector<CellState>;
    struct Cell
    {
        Row row;
        Collumn collumn;
    };

    Grid(Rows row_, Collumns collum_);
    Grid(Grid &grid_);
    Grid(Grid &&grid_);
    auto operator=(Grid &) -> Grid & = default;
    bool ReviveCell(Cell cell);
    bool KillCell(Cell cell);
    Collumns getColumnsSize() const;

    const Values &getValues() const;
    Values &getValues();
    bool operator==(const Grid& rhs);

private:
    bool setCell(Cell cell, CellState state);
    Rows rows;
    Collumns collumns;
    Values values;
};
