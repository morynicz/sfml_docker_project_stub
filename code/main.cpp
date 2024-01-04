#include <SFML/Graphics.hpp>
#include <random>
#include <algorithm>

int main()
{
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> distrib(-2, 2);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::VertexArray wall(sf::PrimitiveType::LineStrip);
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    wall.append(sf::Vertex(sf::Vector2f(0,0), sf::Color::Green, sf::Vector2f(100.f, 100.f)));

    float x=0,y=0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        x= std::clamp<double>(x + distrib(gen), 0.f, 200.f);
        y= std::clamp<double>(y + distrib(gen), 0.f, 200.f);

        wall.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Red, sf::Vector2f(100.f, 100.f)));

        window.clear();
        window.draw(wall);
        window.display();
    }

    return 0;
}