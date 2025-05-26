//Custom Includes
#include "Classes/Player/Player.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <optional>

// Screen Constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Rainy Season", sf::Style::Close); // declare window

    sf::Clock clock; // declare for delta time

    Player player; // declare player class instance

    while (window.isOpen()) // loop when the window is open
    {
        sf::Event event; // declare an event for when an event happens
        
        while (window.pollEvent(event)) // check if window events pressed, i.e. close window
        {
            if (event.type == sf::Event::Closed) // check if window close pressed
            {
                window.close(); // close window
            }      
        }

        float deltaTime = clock.restart().asSeconds();

        player.handleInput(); // handle input
        player.update(deltaTime); // update player location each frame

        window.clear(sf::Color(127, 127, 127)); // turn window to grey
        player.render(window); // render player on window
        window.display(); // display output
    }
    
    return 0;
}