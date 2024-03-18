#include <view/Renderer.hpp>
#include <iostream>

Renderer::Renderer(WindowInfo info_, Scene &scene_)
    : window{{info_.width, info_.height}, info_.title}, scene{scene_}, isSimulationStarted{false}
{
}

void Renderer::loop()
{
    while (window.isOpen())
    {
        auto loopStart = std::chrono::steady_clock::now();
        handleEvents();
        updateDisplay();
        auto loopEnd = std::chrono::steady_clock::now();
        int64_t duration = std::chrono::duration_cast<std::chrono::milliseconds>((loopEnd - loopStart)).count();
        {

            std::unique_lock<std::mutex> lock(mtx);
            cv.wait_for(lock, std::chrono::milliseconds(100 - duration));
        }
    }
}
void Renderer::handleEvents()
{
    for (auto event = sf::Event{}; window.pollEvent(event);)
    {

        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            std::cout << "mouse x: " << event.mouseButton.x << " mouse y: " << event.mouseButton.y << std::endl;
            uint16_t square = scene.visualGrid.getRectangleFromMouseInput(event.mouseButton.x, event.mouseButton.y);
            if (square != UINT16_MAX)
            {
                scene.visualGrid.toggleSquare(square);
            }
        }
        if (scene.startButton.checkMousePressEvent(event))
        {
            isSimulationStarted = !isSimulationStarted;
        }
    }
}
void Renderer::updateDisplay()
{
    if (isSimulationStarted)
    {

        RuleSet g{scene.visualGrid.exportValues()};
        scene.visualGrid.importValues({g.calculate(), scene.visualGrid.getcolums()});
    }
    window.clear();
    window.draw(scene.visualGrid);
    window.draw(scene.startButton);
    window.display();
}
