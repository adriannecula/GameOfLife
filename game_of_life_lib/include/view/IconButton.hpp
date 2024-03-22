#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

class IconButton: public sf::Drawable
{
   public:
    struct Properties
    {
        sf::Vector2f position;
        sf::Vector2f scale;
        sf::Vector2f size;
        sf::Color color;
        sf::Texture icon;
        float angle;
    };

    IconButton(Properties properties_)
    :properties{properties_},sprite{}
    {
        sprite.setTexture(properties.icon);
        sprite.setPosition(properties.position);
        sprite.setScale(properties.scale);
        sprite.setRotation(properties.angle);
    }
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    bool checkMousePressEvent(sf::Event event);
    
    ~IconButton()= default;
    private:
    Properties properties;
    sf::Sprite sprite;

};