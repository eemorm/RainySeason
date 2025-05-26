// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <optional>

struct Tile // tile struct that holds the variables for a tile
{
    char type; // letter type in the json that will be parsed and held
    sf::Sprite sprite; // sprite of the tile
};