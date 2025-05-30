//Custom Includes
#include "Classes/Player/Player.hpp"
#include "STORM - a custom map loader for Rainy Season/Map.hpp"
#include "Textures/Textures.hpp"
#include "UI/InventoryUI.hpp"
#include "Global/Inventory/PlayerInventory.hpp"
#include "Managers/Items/GroundItemManager.hpp"

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

    if (!font.loadFromFile("currentgamefont.ttf")) {
        std::cerr << "Failed to load font!\n";
    }

    Map map; // declare instance of map
    if (!map.loadFromFile("src/STORM - a custom map loader for Rainy Season/map.json", 32)) // if cannot load from file
    {
        std::cerr << "Failed to load map\n"; // send
        return -1;                           // error
    }

    sf::View view(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT)); // set camera view

    initializeTextures(); // initialize textures

    setTestGroundItems(); // write test items to the ground to test item

    initializeInventoryVisual(SCREEN_WIDTH, SCREEN_HEIGHT, playerInventory.getCapacity(), 64.0f, 12.0f, 20.0f); // initialize inventory UI with the correct values

    while (window.isOpen()) // loop when the window is open
    {
        sf::Event event; // declare an event for when an event happens
        
        while (window.pollEvent(event)) // check if window events pressed, i.e. close window
        {
            if (event.type == sf::Event::Closed) // check if window close pressed
            {
                window.close(); // close window
            }     
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Right) // if right mouse button pressed
            {
                window.setView(window.getDefaultView()); // set to UI view
                sf::Vector2f mousePos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}); // get mouse coordinates

                int index = 0; // set an index variable to 0 to keep track of the index of the slot
                for (Slot& slot : getSlots()) // for slot in slots, passing by reference to keep the actual slot
                {
                    if (slot.getBackground().getGlobalBounds().contains(mousePos) && slot.getItem().getCurrentStack() > 0)
                    {   // if stack is greater than 0 and slot has the mouse position
                        sf::Vector2f playerPos = player.getPosition(); // get the player position
                        playerInventory.dropItem(index, {playerPos.x, playerPos.y - 64}); // drop the item from the correct slot a bit up from the player
                        if (selectedSlotIndex != -1) // if slot does contain item
                        {
                            slots[selectedSlotIndex].highlight(false); // unhighlight
                            selectedSlotIndex = -1; // set the slot index back to -1 because no slot is selected
                        }                        
                        
                        break; // Only process 1 slot
                    }
                    index++; // add 1 to the index when the slot is not the correct one
                }
            }        
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) // if the left mouse button is pressed
            {
                window.setView(window.getDefaultView()); // set to the UI view
                sf::Vector2f mousePos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}); // set the mouse position to coordinates

                for (int i = 0; i < slots.size(); ++i)  // for slot in slots
                {
                    if (slots[i].getBackground().getGlobalBounds().contains(mousePos)) // if mouse in the slot
                    {
                        if (selectedSlotIndex != -1 && selectedSlotIndex != i) // if selected slot is not the current and at least one is selected
                            slots[selectedSlotIndex].highlight(false); // unhighlight previous slot
                
                        if (slots[i].getItem().getCurrentStack() > 0) // if there is an item in the slot
                        {
                            selectedSlotIndex = i; // set new slot
                            slots[i].highlight(true); // highlight current slot
                        }
                        break; // leave the loop
                    }
                }                
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
        for (auto item : groundItems) // for every item in ground items
        {
            item.displayItemSpriteOnGround(window); // display the item on the ground, drawn on the window
        }
        player.pickupItem(32); // try to pick any items in the player's radius
        window.setView(window.getDefaultView()); // set view so that the slots can be drawn in the right place
        updateInventoryVisual(); // update the inventory and prep it to be displayed
        int i = 0; // set variable to keep track of which slot the loop is on so that it can be compared to the selected slot index
        for (Slot& slot : getSlots()) // for slot in slots
        {
            if (i == selectedSlotIndex) // if the loop is on the correct selected slot
            {
                slot.getBackground().setOutlineThickness(2.f); // set the outline thickness
                slot.getBackground().setOutlineColor(sf::Color::Yellow); // set the outline color to yellow for visibility
            }
            else // otherwise
            {
                slot.getBackground().setOutlineThickness(0.f); // set the outline thickness to something else
            }

            window.draw(slot.getBackground()); // draw the background first

            if (slot.getItem().getSprite().getTexture() != nullptr) // only if there is a sprite
                window.draw(slot.getItem().getSprite()); // draw the sprite

            if (slot.getItem().getCurrentStack() > 1) // only show the quantity text if there is more than 1 item
            {
                sf::Text text; // declare text
                text.setFont(font); // set the font
                text.setString(std::to_string(slot.getItem().getCurrentStack())); // set the text to the number of the quantity
                text.setCharacterSize(14); // set font size
                text.setFillColor(sf::Color::White); // text color set
                sf::FloatRect textBounds = text.getLocalBounds(); // get the local bounds of the text
                text.setOrigin(textBounds.width, 0); // right-align the text
                text.setPosition(slot.getPosition().x + slot.getSize() - 4, slot.getPosition().y + 2); // set the text position
                window.draw(text); // and finally draw the text
            }
            i++; // increase the tracking variable for the loop
        }
        window.display(); // display output
    }
    
    return 0; // return 0 to finish the main function when the game is quit
}