#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

#include <cstdint>

class MessageBox : public sf::Drawable
{
public:
    struct Properties
    {
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Color fillColor;
        sf::Color outlineColor;
        float outlineTickeness;
        std::string message;
        sf::Font font;
        sf::Texture icon;
    };

    MessageBox(Properties properties_)
        : properties{properties_},
          rectangle{properties_.size},
          text{properties.message, properties.font, 20}
    {
        rectangle.setPosition(properties_.position);
        rectangle.setFillColor(properties_.fillColor);
        rectangle.setOutlineColor(properties.outlineColor);
        rectangle.setOutlineThickness(properties.outlineTickeness);
        text.setPosition(properties.position);
    }
    
    ~MessageBox()= default;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setText (std::string text);
    bool checkMousePressEvent(sf::Event event);
private:
    Properties properties;
    sf::RectangleShape rectangle;
    sf::Text text;
};

using ButtonHandle = std::shared_ptr<MessageBox>;