// Custom Includes
#include "Classes/Items/Item.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

struct GroundItem 
{
    Item item; // the type of item that is on the ground
    sf::Vector2f position; // the position of the item
};