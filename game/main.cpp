
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <view/IconButton.hpp>
#include <view/MessageBox.hpp>
#include <view/VisualGrid.hpp>
#include <view/Renderer.hpp>

#include <controller/RuleSet.hpp>

#include "Configuration.hpp"

int main()
{
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

    sf::Texture playIcon;
    if (!playIcon.loadFromFile(resources::playIcon))
    {
        return false;
    }

    sf::Texture stopIcon;
    if (!stopIcon.loadFromFile(resources::stopIcon))
    {
        return false;
    }

    VisualGrid::Configuration visualGridConfig{
        .rows{(window::windowHeight - (window::windowHeight / 10)) / grid::intCellSize},
        .columns{window::windowWidth / grid::intCellSize},
        .cellSize{grid::cellSize},
        .offsetX{0},
        .offsetY{0}};
    visualGridConfig.offsetX = (window::windowWidth - (visualGridConfig.columns * grid::intCellSize)) / 2;
    visualGridConfig.offsetY = 20;

    VisualGrid visualGrid{visualGridConfig};
    visualGrid.generateGrid();

    IconButton::Properties startButtonProperties =
    {
        .position = {window::windowWidth / 2 -button::width, visualGridConfig.rows * grid::cellSize +  button::height/2},
        .scale = {0.8,0.8,},
        .size = {button::width, button::height},
       
        .icon = playIcon,
        .angle =0.0f
        
    };
    
    IconButton::Properties stopButtonProperties=
    {
        .position = {window::windowWidth / 2 +button::width, visualGridConfig.rows * grid::cellSize + button::height/2},
        .scale = {0.8,0.8},
        .size = {button::width, button::height},
       
        .icon = stopIcon,
        .angle =0.0f
    };        

    IconButton startButton{startButtonProperties};
    IconButton stopButton{stopButtonProperties};

    MessageBox::Properties statusProperties=
    {
        .position = {window::windowWidth / 2 +4*button::width, visualGridConfig.rows * grid::cellSize + button::height},
        .size ={messageBox::width, messageBox::height},
        .fillColor = sf::Color::Transparent,
        .outlineColor = sf::Color::Magenta,
        .outlineTickeness = 1.0f,
        .message ="Stopped",
        .font = font

    };
    MessageBox status{statusProperties};

     MessageBox::Properties iterationTextProperties=
    {
        .position = {window::windowWidth / 2 +button::width+messageBox::width, visualGridConfig.rows * grid::cellSize + 2*button::height},
        .size ={messageBox::width, messageBox::height},
        .fillColor = sf::Color::Transparent,
        .outlineColor = sf::Color::Blue,
        .outlineTickeness = 1.0f,
        .message ="Iteration",
        .font = font
    };
    MessageBox iterationText{iterationTextProperties};
    MessageBox::Properties iterationNumberProperties=
    {
        .position = {window::windowWidth / 2 +4*button::width+messageBox::width, visualGridConfig.rows * grid::cellSize + 2*button::height},
        .size ={messageBox::width, messageBox::height},
        .fillColor = sf::Color::Transparent,
        .outlineColor = sf::Color::Blue,
        .outlineTickeness = 1.0f,
        .message ="0",
        .font = font
    };
    MessageBox iterationNumber{iterationNumberProperties};

    Scene scene{
        .visualGrid = visualGrid,
        .startButton = startButton,
        .stopButton = stopButton,
        .staus = status,
        .iterationText = iterationText,
        .iterationNumber = iterationNumber
    };

    Renderer rnd{info, scene};
    rnd.loop();

    return EXIT_SUCCESS;
}