#pragma once
#include <SFML/Graphics.hpp>
#include <view/IconButton.hpp>
#include <view/MessageBox.hpp>
#include <controller/RuleSet.hpp>
#include <view/VisualGrid.hpp>

#include <condition_variable>
#include <mutex>
struct Scene
{
    VisualGrid visualGrid;
    IconButton startButton;
    IconButton stopButton;
    MessageBox staus;
    MessageBox iterationText;
    MessageBox iterationNumber;
};

struct WindowInfo
{
    uint32_t width;
    uint32_t height;
    uint32_t frameLimit;
    std::string title;
};

class Renderer
{
public:
    Renderer(WindowInfo info_, Scene &scene_);
    void loop();
    void handleEvents();
    void updateDisplay();

private:
    Scene scene;
    sf::RenderWindow window;
    bool isSimulationStarted;
    std::mutex mtx;
    std::condition_variable cv;
    RuleSet ruleSet;
};