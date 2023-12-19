#pragma once

#include  <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>


#include <cstdint>

class Button: public sf::Drawable
{
public:
    struct Properties
    {
        sf::Vector2f position; 
        sf::Vector2f size; 
        sf::Color color;
        std::string message; 
        sf::Font font;
    };

    Button(Properties properties_)
    : properties{properties_},
    rectangle{properties_.size},
    text{properties.message, properties.font,20}
    {
        rectangle.setPosition(properties_.position);
        rectangle.setFillColor(properties_.color);
        text.setPosition(properties.position);        
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool checkMousePressEvent(sf::Event event);
private:
    Properties properties; 
    sf::RectangleShape rectangle;
    sf::Text text;
};

using ButtonHandle = std::shared_ptr<Button>;