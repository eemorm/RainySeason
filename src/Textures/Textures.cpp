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

sf::Texture carrotTexture;
sf::Texture carrotseedgroundTexture;
sf::Texture carrotsproutTexture;
sf::Texture carrotgrownTexture;

void initializeTextures()
{
    if (!carrotTexture.loadFromFile("assets/Plants/carrot.png"))
        std::cerr << "Failed to load carrot texture\n";

    if (!carrotseedgroundTexture.loadFromFile("assets/Plants/carrotseedground.png"))
        std::cerr << "Failed to load carrot texture\n";

    if (!carrotsproutTexture.loadFromFile("assets/Plants/carrotsprout.png"))
        std::cerr << "Failed to load carrot texture\n";

    if (!carrotgrownTexture.loadFromFile("assets/Plants/carrotgrown.png"))
        std::cerr << "Failed to load carrot texture\n";
}