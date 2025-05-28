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

sf::Texture loadTexture(const std::string &filepath) 
{
    sf::Texture tex;
    tex.loadFromFile(filepath);
    return tex;
}

extern sf::Sprite carrot;
extern sf::Sprite carrotseedground;
extern sf::Sprite carrotsprout;
extern sf::Sprite carrotgrown;

void textureSetup()
{
    carrot.setTexture(loadTexture("assets/Plants/carrot"));
    carrotseedground.setTexture(loadTexture("assets/Plants/carrotseedground"));
    carrotsprout.setTexture(loadTexture("assets/Plants/carrotsprout"));
    carrotgrown.setTexture(loadTexture("assets/Plants/carrotgrown"));
}