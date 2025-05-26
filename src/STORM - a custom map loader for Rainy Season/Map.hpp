//Custom Includes
#include "Tile.hpp"
#include "nlohmann's JSON Parser/json.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

class Map 
{
    private:
        std::vector<std::vector<Tile>> tilemap; // vector of a vector that holds tiles. this is the actual tilemap that will be displayed.
        std::unordered_map<char, sf::Texture> tileTextures;
    public:
        bool loadFromFile(const std::string &path, int tileSize) // loads the json and converts letters to tiles
        {
            std::ifstream file(path); // find and open path
            if (!file.is_open()) return false; // if the file can not open return false because the map cannot be loaded :(

            nlohmann::json j;
            file >> j;

            // declare each different letter in the json to the tile it matches
            tileTextures['G'].loadFromFile("assets/tiles/grass.png"); // Grass
            tileTextures['W'].loadFromFile("assets/tiles/water.png"); // Water

            tilemap.clear(); // clear tilemap before
            for (size_t y = 0; y < j.size(); ++y)
            {
                std::vector<Tile> row;
                for (size_t x = 0; x < j[y].size(); ++x)
                {
                    char type = j[y][x].get<std::string>()[0];
                    Tile tile;
                    tile.type = type;
                    tile.sprite.setTexture(tileTextures[type]);
                    tile.sprite.setScale(
                        static_cast<float>(tileSize) / tileTextures[type].getSize().x,
                        static_cast<float>(tileSize) / tileTextures[type].getSize().y
                    );
                    tile.sprite.setPosition(x * tileSize, y * tileSize);
                    row.push_back(tile);
                }
                tilemap.push_back(row);
            }

            return true;
        }
        void draw(sf::RenderWindow &window) // draws the map
        {
            for (const auto& row : tilemap) // for each row in the map
                for (const auto& tile : row) // then for each tile in the row
                    window.draw(tile.sprite); // draw the sprite
        }
};
    