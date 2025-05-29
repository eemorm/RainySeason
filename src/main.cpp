//Custom Includes
#include "Classes/Player/Player.hpp"
#include "STORM - a custom map loader for Rainy Season/Map.hpp"
#include "Textures/Textures.hpp"
#include "UI/InventoryUI.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Libraries
#include <iostream>
#include <optional>
#include <filesystem>

// Screen Constants
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

int main() // main function, where the flow of the game starts
{
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Rainy Season", sf::Style::Close); // declare window

    window.setFramerateLimit(60); // set fps limit to avoid too much GPU stress

    sf::Clock clock; // declare for delta time

    Player player; // declare player class instance

    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl; // print out current working directory

    Map map; // declare instance of map
    if (!map.loadFromFile("src/STORM - a custom map loader for Rainy Season/map.json", 32)) // if cannot load from file
    {
        std::cerr << "Failed to load map\n"; // send
        return -1;                           // error
    }

    sf::View view(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT)); // set camera view

    initializeTextures(); // initialize textures

    initializeInventoryVisual(SCREEN_WIDTH, SCREEN_HEIGHT, 9, 64.0f, 12.0f, 20.0f); // initialize inventory UI with the correct values

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

        float deltaTime = clock.restart().asSeconds(); // start delta time

        player.handleInput(); // handle input
        player.update(deltaTime); // update player location each frame

        sf::Vector2f playerPos = player.getPosition(); // get player position
        view.setCenter(playerPos); // set center of view to the player position
        window.setView(view); // set window view to the center view on the player

        window.clear(sf::Color(127, 127, 127)); // turn window to grey
        map.draw(window); // draw map
        player.render(window); // render player on window over map
        window.setView(window.getDefaultView()); // set view so that the slots can be drawn in the right place
        for (auto& slot : getSlots()) { window.draw(slot.getBackground()); window.draw(slot.getSprite()); } // for every slot in the vector draw the slot at the appropriate position, first the background and then the sprite and number
        window.display(); // display output
    }
    
    return 0; // return 0 to finish the main function when the game is quit
}