#include <iostream>
#include <view/Button.hpp>
#include <SFML/Graphics.hpp>

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rectangle);
    target.draw(text);
}

bool Button::checkMousePressEvent(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (rectangle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            return true;
            std::cout << "Button pressed\n"
                      << std::endl;
        }
    }
    return false;
}