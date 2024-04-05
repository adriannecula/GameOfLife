#include <view/IconButton.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

void IconButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite);
}

bool IconButton::checkMousePressEvent(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            return true;
            std::cout << "Button pressed\n"
                      << std::endl;
        }
    }
    return false;
}