// Custom Includes
#include "Textures.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Libraries
#include <iostream>
#include <string>
#include <filesystem>

sf::Sprite carrot;
sf::Sprite carrotseedground;
sf::Sprite carrotsprout;
sf::Sprite carrotgrown;

sf::Texture loadTexture(const std::string &filepath) 
{
    sf::Texture tex;
    tex.loadFromFile(filepath);
    return tex;
}

void initializeTextures()
{
    carrot.setTexture(loadTexture("assets/Plants/carrot.png"));
    carrotseedground.setTexture(loadTexture("assets/Plants/carrotseedground.png"));
    carrotsprout.setTexture(loadTexture("assets/Plants/carrotsprout.png"));
    carrotgrown.setTexture(loadTexture("assets/Plants/carrotgrown.png"));
}