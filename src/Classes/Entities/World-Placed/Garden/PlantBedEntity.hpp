#pragma once

//Custom Includes
#include "Classes/Items/PlantBedItem.hpp"
#include "Classes/Entities/World-Placed/PlaceableEntity.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Libraries
#include <iostream>
#include <vector>

class PlantBedEntity : public PlaceableEntity
{
    private:
        std::vector<std::vector<Plant>> plants; // plants in the bed
        sf::Vector2f size; // size of the bed
        int rotation; // rotation of the bed

    public:
        PlantBedEntity(sf::Vector2f s, sf::Vector2f p) // constructor
        {
            size = s;
            position = p;
            sprite.setSize({size.x * 32, size.y * 32}); // set size
            sprite.setPosition(p); // set position
            sprite.setFillColor(sf::Color(139, 69, 19)); // set fill color, brown dirt rectangle
        }
        ~PlantBedEntity() {} // deconstructor
        // ********************       
        sf::Vector2f getSize() { return size; }                
        int getRotation() { return rotation; }        
        void setRotation(int r) { rotation = r; }
        std::vector<std::vector<Plant>> getPlants() { return plants; }
        void setPlant(std::vector<std::vector<Plant>> p) { plants = p; }
        // ********************
        void rotateClockwise() { rotation = (rotation + 90) % 360; } // rotate the plant bed clockwise
        void rotateCounterClockwise() { rotation = (rotation + 270) % 360; } // rotate the plant bed counterclockwise
};
