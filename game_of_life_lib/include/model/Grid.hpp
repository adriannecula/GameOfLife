#pragma once
#include <cstdint>
#include <vector>

class Grid
{
public:
    using Rows = uint32_t;
    using Collumns = uint32_t;
    using Row = uint32_t;
    using Collumn = uint32_t;
    enum class CellState : uint8_t
    {
        Alive,
        Dead
    };
    using Array = std::vector<CellState>;
    struct Cell
    {
        Row row;
        Collumn collumn;
    };

    Grid(Rows row_, Collumns collum_);
    Grid(Rows row_, Collumns collum_, Array& grid_);
    Grid(Grid &grid_);
    Grid(Grid &&grid_);
    auto operator=(Grid &) -> Grid & = default;
    bool ReviveCell(Cell cell);
    bool KillCell(Cell cell);
    Collumns getColumnsSize() const;

    bool operator==(const Grid& rhs) const;
    const Array &getArray() const;
    Array &getArray();

private:
    bool setCell(Cell cell, CellState state);
    Rows rows;
    Collumns collumns;
    Array values;

};
