
#include <SFML/Graphics.hpp>

int main()
{
    // Create the game window
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Dungeon Project"
    );

    // Create our player
   sf::RectangleShape player({40.f, 40.f});
    player.setFillColor(sf::Color::Green);
    player.setPosition({380.f, 280.f});

    sf::Clock clock;

    // Game loop
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

       // Move the player
           float deltaTime = clock.restart().asSeconds();
            float speed = 200.0f;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                player.move({0.f, -speed * deltaTime});
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                player.move({0.f, speed * deltaTime});
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                player.move({-speed * deltaTime, 0.f});
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                player.move({speed * deltaTime, 0.f});
            }

            window.clear();
            window.draw(player);
            window.display();
                }

    return 0;
}
