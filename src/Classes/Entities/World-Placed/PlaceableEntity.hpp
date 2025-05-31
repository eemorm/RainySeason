#pragma once

//Custom Includes
#include "Classes/Entities/Entity.hpp"
#include "Classes/Items/Item.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Libraries
#include <iostream>
#include <vector>

class PlaceableEntity : public Entity
{
    protected:
        sf::Vector2f position; // entity position
        Item itemData; // item associated with the entity
        sf::RectangleShape sprite; // sprite of the entity
    public:
        sf::Vector2f getPosition() const { return position; } 
        void setPosition(sf::Vector2f p) { position = p; sprite.setPosition(p); }   
        Item& getItemData() { return itemData; } 
        void setItemData(Item& id) { itemData = id; }
        sf::RectangleShape& getSprite() { return sprite; }
        void setSprite(sf::RectangleShape s) { sprite = s; }
        // ********************
        void draw(sf::RenderWindow& window) { window.draw(sprite); } // draw the plant bed
};