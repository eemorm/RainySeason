// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Libraries
#include <iostream>
#include <string>

extern sf::Sprite carrot;
extern sf::Sprite carrotseedground;
extern sf::Sprite carrotsprout;
extern sf::Sprite carrotgrown;

sf::Texture loadTexture(const std::string &filepath);
void initializeTextures();