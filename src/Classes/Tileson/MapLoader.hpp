#pragma once

// Custom Headers
#include "src/Classes/Tileson/tileson.hpp"

// Standard Output
#include <iostream>
#include <string>

class MapLoader // map loader class
{
    private:
        std::unique_ptr<tson::Tileson> t_parser;
        std::unique_ptr<tson::Map> t_map; // now a unique_ptr

    public:
        MapLoader() // constructor
        {
            t_parser = std::make_unique<tson::Tileson>();
        }

        // Function that returns true if map is loaded successfully
        bool loadMap(const std::string &path)
        {
            t_map = t_parser->parse(path);

            if (!t_map || t_map->getStatus() != tson::ParseStatus::OK)
            {
                std::cerr << "Map parsing failed: " << (t_map ? t_map->getStatusMessage() : "null map") << "\n";
                return false;
            }

            return !t_map->getTilesets().empty();
        }
        // Returns a reference to the map
        tson::Map* getMap()
        {
            return t_map.get();
        }
};