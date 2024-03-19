
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <view/Button.hpp>
#include <view/VisualGrid.hpp>
#include <view/Renderer.hpp>

#include <controller/RuleSet.hpp>
#include <model/Grid.hpp>

#include "Configuration.hpp"

int main()
{
    
    Grid g{Grid::Rows{5},Grid::Collumns{5}};
    
    
    WindowInfo info{
        .width{window::windowWidth},
        .height{window::windowHeight},
        .frameLimit{window::frameLimit},
        .title{window::title}};

    sf::Font font;
    if (!font.loadFromFile(resources::fontLocation))
    {
        return false;
    }

    VisualGrid::Configuration visualGridConfig{
        .rows{(window::windowHeight - (window::windowHeight / 10)) / grid::intCellSize},
        .columns{(window::windowWidth - (window::windowWidth / 10)) / grid::intCellSize},
        .cellSize{grid::cellSize},
        .offsetX{0},
        .offsetY{0}};
    visualGridConfig.offsetX = (window::windowWidth - (visualGridConfig.columns * grid::intCellSize)) / 2;
    visualGridConfig.offsetY = 20;

    VisualGrid visualGrid{visualGridConfig};
    visualGrid.generateGrid();

    Button::Properties properties =
        {
            .position = {window::windowWidth / 2, visualGridConfig.rows * grid::cellSize + 2 * button::height},
            .size = {button::width, button::height},
            .color = sf::Color::Green,
            .message = "Start",
            .font = font};

    Button startButton{properties};

    Scene scene{
        .visualGrid = visualGrid,
        .startButton = startButton};

    Renderer rnd{info, scene};
    rnd.loop();

    return EXIT_SUCCESS;
}