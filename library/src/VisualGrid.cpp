#include "../include/VisualGrid.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void VisualGrid::generateGrid()
{
    for (int y = 0; y < config.rows; y++)
    {
        for (int x = 0; x < config.columns; x++)
        {

            sf::RectangleShape rectangle{sf::Vector2f{config.cellSize, config.cellSize}};

            rectangle.setPosition(config.offsetX+x * config.cellSize, config.offsetY +y  * config.cellSize);
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

std::pair<std::vector<uint8_t>,uint16_t> VisualGrid::exportValues() const
{
    std::vector<uint8_t> values;
    for (const auto &rectangle : rectangles)
    {
        rectangle.getFillColor() == inactiveColor ? values.push_back(0) : values.push_back(1);
    }
    return std::make_pair(values, config.columns);
}

void VisualGrid::importValues(std::pair<std::vector<uint8_t>,uint16_t> grid)
{
    if (config.columns != grid.second)
    {
        return;
    }
    std::transform(rectangles.begin(), rectangles.end(), grid.first.begin(), rectangles.begin(),
                   [this](sf::RectangleShape &rect, uint8_t &val)
                   {
                       val == 0 ? rect.setFillColor(this->inactiveColor) : rect.setFillColor(this->activeColor);
                       return rect;
                   });
}

uint16_t VisualGrid::getRectangleFromMouseInput(uint16_t x, uint16_t y) const
{
    // TODO: if line on the border
     int32_t normX = x- config.offsetX;
     int32_t normY = y- config.offsetY;
     if( normX  <0 || normY  < 0
        || normX > config.columns* static_cast<int>(std::round(config.cellSize)) 
        || normY > config.rows* static_cast<int>(std::round(config.cellSize)))
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