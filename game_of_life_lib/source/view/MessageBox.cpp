#include <iostream>
#include <view/MessageBox.hpp>
#include <SFML/Graphics.hpp>

void MessageBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rectangle);
    target.draw(text);
}

bool MessageBox::checkMousePressEvent(sf::Event event)
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
void MessageBox::setText (std::string message)
{
    text.setString(message); 
}