// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Libraries
#include <iostream>
#include <string>

sf::Texture loadTexture(const std::string &filepath);
void textureSetup();

sf::Sprite carrot;
sf::Sprite carrotseedground;
sf::Sprite carrotsprout;
sf::Sprite carrotgrown;