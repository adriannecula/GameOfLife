#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include <cstdint>
#include <vector>
#include <utility>
#include <memory>
class VisualGrid : public sf::Drawable
{
public:
    struct Configuration
    {
        uint16_t rows;
        uint16_t columns;
        float cellSize;
        uint16_t offsetX;
        uint16_t offsetY;
    };
    VisualGrid(Configuration config_)
        : config{config_} {}

    void generateGrid();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void toggleSquare(uint16_t index);
    uint16_t getRectangleFromMouseInput(uint16_t colum, uint16_t row) const;
    std::pair<std::vector<uint8_t>, uint16_t> exportValues() const;
    void importValues(std::pair<std::vector<uint8_t>, uint16_t> grid);
    uint16_t getcolums()
    {
        return config.columns;
    }

private:
    std::vector<sf::RectangleShape> rectangles;
    Configuration config;
    sf::Vector2u offset;
    const sf::Color activeColor{sf::Color::Blue};
    const sf::Color inactiveColor{sf::Color{128, 128, 128}};
};

using VisualGridHandle = std::shared_ptr<VisualGrid>;