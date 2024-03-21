#include <view/VisualGrid.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <model/Grid.hpp>

void VisualGrid::generateGrid()
{
    for (int y = 0; y < config.rows; y++)
    {
        for (int x = 0; x < config.columns; x++)
        {

            sf::RectangleShape rectangle{sf::Vector2f{config.cellSize, config.cellSize}};

            rectangle.setPosition(config.offsetX + x * config.cellSize, config.offsetY + y * config.cellSize);
            rectangle.setOutlineColor(sf::Color::White);
            rectangle.setOutlineThickness(1.f);
            rectangle.setFillColor(inactiveColor);
            rectangles.push_back(rectangle);
        }
    }
}

void VisualGrid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto &rectangle : rectangles)
    {
        target.draw(rectangle);
    }
}

void VisualGrid::toggleSquare(uint16_t index)
{
    if (index >= rectangles.size())
    {
        return;
    }
    rectangles[index].getFillColor() == inactiveColor ? rectangles[index].setFillColor(activeColor) : rectangles[index].setFillColor(inactiveColor);
}

Grid VisualGrid::exportValues() const
{
    Grid grid{Grid::Rows{config.rows}, Grid::Collumns{config.columns}};
    Grid::Array &vector = grid.getArray();

    for (const auto &rectangle : rectangles)
    {
        rectangle.getFillColor() == inactiveColor ? vector.push_back(Grid::CellState::Dead) : vector.push_back(Grid::CellState::Alive);
    }
    return grid;
}

void VisualGrid::importValues(Grid grid)
{
    if (config.columns != grid.getColumnsSize())
    {
        return;
    }
    Grid::Array &values = grid.getArray();

    std::transform(rectangles.begin(), rectangles.end(), values.begin(), rectangles.begin(),
                   [this](sf::RectangleShape &rect, Grid::CellState &state)
                   {
                       state == Grid::CellState::Dead ? rect.setFillColor(this->inactiveColor) : rect.setFillColor(this->activeColor);
                       return rect;
                   });
}

uint16_t VisualGrid::getRectangleFromMouseInput(uint16_t x, uint16_t y) const
{
    // TODO: if line on the border
    int32_t normX = x - config.offsetX;
    int32_t normY = y - config.offsetY;
    if (normX < 0 || normY < 0 || normX > config.columns * static_cast<int>(std::round(config.cellSize)) || normY > config.rows * static_cast<int>(std::round(config.cellSize)))
    {
        return UINT16_MAX;
    }

    uint16_t cellSizeRound = static_cast<int>(std::round(config.cellSize));
    std::cout << "celsize: " << cellSizeRound << std::endl;
    uint16_t columInGrid = normX / cellSizeRound;
    std::cout << "columInGrid: " << columInGrid << std::endl;
    uint16_t rowInGrid = normY / cellSizeRound;
    std::cout << "rowInGrid: " << rowInGrid << std::endl;
    return rowInGrid * config.columns + columInGrid;
}