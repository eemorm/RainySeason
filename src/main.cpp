// Custom Includes
#include "Classes/Tileson/MapLoader.hpp"
#include "Classes/Player/Player.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Includes
#include <iostream>
#include <optional>
#include <filesystem>
#include <vector>

// Screen Constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Tile scale to shrink the tiles for proper display
const float TILE_SCALE = 0.5f;

int main()
{
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Rainy Season", sf::Style::Close);
    sf::Clock clock;

    Player player;
    MapLoader loader;
    tson::Map* map = nullptr;

    if (loader.loadMap("../maps/groundmap.json"))
    {
        std::cout << "Map loaded successfully!" << std::endl;
        map = loader.getMap();

        if (map)
            std::cout << "Map size: " << map->getSize().x << "x" << map->getSize().y << std::endl;
        else
        {
            std::cerr << "Map pointer is null." << std::endl;
            return -1;
        }
    }
    else
    {
        std::cerr << "Failed to load map." << std::endl;
        return -1;
    }

    // Load tileset textures
    std::vector<sf::Texture> tilesetTextures;
    std::filesystem::path mapDir = "../maps/";

    for (auto& tileset : map->getTilesets())
    {
        sf::Texture texture;
        std::filesystem::path fullImagePath = mapDir / tileset.getImagePath();

        if (!texture.loadFromFile(fullImagePath.string()))
        {
            std::cerr << "Failed to load tileset image: " << fullImagePath << std::endl;
            return -1;
        }

        tilesetTextures.push_back(std::move(texture));
    }

    for (size_t i = 0; i < tilesetTextures.size(); ++i)
    {
        std::cout << "Tileset texture " << i << " size: "
                  << tilesetTextures[i].getSize().x << "x"
                  << tilesetTextures[i].getSize().y << std::endl;
    }

    // Setup the view for the camera
    sf::View view(sf::FloatRect(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        player.handleInput();
        player.update(deltaTime);

        // Update the camera to follow the player
        sf::Vector2f playerPos = player.getPosition(); // Assuming Player has getPosition() returning sf::Vector2f
        view.setCenter(playerPos);
        window.setView(view);

        window.clear(sf::Color(127, 127, 127));

        // Render tile layers
        for (auto& layer : map->getLayers())
        {
            if (!layer.isVisible())
                continue;

            if (layer.getType() != tson::LayerType::TileLayer)
                continue;

            // Get tile objects for the layer
            auto& tileObjects = layer.getTileObjects();

            for (const auto& [pos, tileObj] : tileObjects)
            {
                // getTile() is non-const, so we use const_cast here
                tson::Tile* tilePtr = const_cast<tson::TileObject&>(tileObj).getTile();
                if (!tilePtr)
                    continue;

                const tson::Tileset* tileset = tilePtr->getTileset();
                if (!tileset)
                    continue;

                int tileIndex = tilePtr->getId();
                int columns = tileset->getColumns();
                tson::Vector2i tileSize = tileset->getTileSize();

                int tsX = (tileIndex % columns) * tileSize.x;
                int tsY = (tileIndex / columns) * tileSize.y;

                // Find which texture corresponds to this tileset
                const auto& tilesets = map->getTilesets();
                size_t textureIndex = std::distance(tilesets.begin(),
                    std::find_if(tilesets.begin(), tilesets.end(),
                        [&](const tson::Tileset& ts) {
                            return ts.getName() == tileset->getName();
                        }));

                if (textureIndex >= tilesetTextures.size())
                    continue;

                sf::Sprite sprite;
                sprite.setTexture(tilesetTextures[textureIndex]);
                sprite.setTextureRect(sf::IntRect(tsX, tsY, tileSize.x, tileSize.y));

                int tileX = std::get<0>(pos);
                int tileY = std::get<1>(pos);

                // Position sprite and scale down so it fits better
                sprite.setPosition(tileX * tileSize.x * TILE_SCALE,
                                   tileY * tileSize.y * TILE_SCALE);

                sprite.setScale(TILE_SCALE, TILE_SCALE);

                window.draw(sprite);
            }
        }

        player.render(window);

        window.display();
    }

    return 0;
}