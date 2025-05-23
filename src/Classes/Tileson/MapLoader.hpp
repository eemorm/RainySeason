#pragma once

// Custom Headers
#include "src/Classes/Tileson/tileson.hpp"

// Standard Output
#include <memory>
#include <string>

class MapLoader // map loader class
{
    private:
        std::unique_ptr<tson::Tileson> t_parser;
        std::shared_ptr<tson::Map> t_map;
    public:
        MapLoader() // contructor
        {
            t_parser = std::make_unique<tson::Tileson>();
        }
        // ********************// function that returns true if map is loaded and false if not
        bool loadMap(const std::string &path) 
        {
            t_map = t_parser->parse(path);
            return !t_map->getTilesets().empty();
        }
        std::shared_ptr<tson::Map> getMap() const // returns the map I believe
        {
            return t_map;
        }
};
