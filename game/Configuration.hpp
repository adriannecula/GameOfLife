#pragma once
#include <cstdint>
#include <string>
namespace window
{
    constexpr uint32_t windowHeight{720};
    constexpr uint32_t windowWidth{1280};
    constexpr uint32_t frameLimit{144};
    constexpr char title[13]{"Game of life"};
}

namespace grid
{
    constexpr uint16_t columns{10};
    constexpr uint16_t rows{10};
    constexpr float cellSize{30};
    constexpr uint16_t intCellSize{30};
}

namespace resources
{
    const std::string fontLocation = "../resources/font/geo_1.ttf";
    const std::string playIcon = "../resources/textures/start96.png";
    const std::string stopIcon = "../resources/textures/stop96.png";
                                   
}

namespace button
{
    const uint16_t width =30;
    const uint16_t height = 30;
}

namespace messageBox
{
    const uint16_t width = 90;
    const uint16_t height = 25;
}