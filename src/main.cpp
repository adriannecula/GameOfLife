#include <SFML/Graphics.hpp>
#include <iostream>
void createCell(const uint32_t x, const uint32_t y, const uint32_t cellSize,sf::VertexArray& grid_) 
{
    sf::Vertex topLeft;
    sf::Vertex topRight;
    sf::Vertex bottomLeft;
    sf::Vertex bottomRight;
    sf::Vertex closing;
    
    float pixelX = x* cellSize;
    float pixelY = y * cellSize;

std::cout<<pixelX<<" "<<pixelY<<std::endl;
    topLeft     .position = { pixelX,               pixelY };
    topRight    .position = { pixelX + cellSize,    pixelY };
    bottomLeft  .position = { pixelX,               pixelY + cellSize };
    bottomRight .position = { pixelX + cellSize,    pixelY + cellSize };
    closing .position={ pixelX,               pixelY };

    grid_.append(topLeft);
    grid_.append(topRight);
    grid_.append(bottomRight);
    grid_.append(bottomLeft);
    grid_.append(closing);
    
 
 

}

int main()
{
    auto window = sf::RenderWindow{ { 800u, 600u }, "Game ofLife " };
    window.setFramerateLimit(144);

    const float gridSizeF = 100.f;
    const uint16_t gridSizeU = 100;

    //const uint32_t colums = 2;
   // const uint32_t rows = 2;
    const uint32_t celSize = 100;
    const uint8_t points = 5;

    // sf::VertexArray grid{sf::PrimitiveType::LineStrip};
    
    // for (auto col=0; col < colums; ++col) {
    //     for(auto row=0; row < rows; ++row) {
    //         createCell(row, col, celSize, grid);
    //     }
    // }
        


    int columns=1000;
    int rows=100;
    float cellSize=20;
    sf::VertexArray vertexGrid(sf::Lines);
    for (int x = 0; x <= columns; x++) {
            sf::Vertex top(cellSize * sf::Vector2f(x, 0), sf::Color::White);
            sf::Vertex bottom(cellSize * sf::Vector2f(x, rows),sf::Color::White);
            vertexGrid.append(top);
            vertexGrid.append(bottom);
    }
    for (int y = 0; y <= rows; y++) {
        sf::Vertex left(cellSize * sf::Vector2f(0, y), sf::Color::White);
        sf::Vertex right(cellSize * sf::Vector2f(columns, y),sf::Color::White);
        vertexGrid.append(left);
        vertexGrid.append(right);
    }
   

    // https://gist.github.com/MarioLiebisch/8322b5e820b22dd2a97171747ee17b13
    //https://www.sfml-dev.org/tutorials/2.6/graphics-vertex-array.php
  
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
  
        window.clear();
        window.draw(vertexGrid);
        window.display();
    }

    return EXIT_SUCCESS;
}