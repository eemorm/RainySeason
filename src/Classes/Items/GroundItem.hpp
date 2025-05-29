#pragma once

// Custom Includes
#include "Classes/Items/Item.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class GroundItem 
{
    private:
        Item item; // the type of item that is on the ground
        sf::Vector2f position; // the position of the item
    public:
        GroundItem() {}
        GroundItem(Item i, sf::Vector2f p) { item = i; position = p; }
        ~GroundItem() {}
        // ********************
        Item& getItem() { return item; }                      // getters
        void setItem(Item i) { item = i; }                   // and
        sf::Vector2f getPosition() { return position; }      // setters
        void setPosition(sf::Vector2f p) { position = p; }    
        // ********************
        void displayItemSpriteOnGround(sf::RenderWindow& window)
        {
            sf::Sprite s = item.getSprite();
            s.setPosition(position);
            auto texSize = s.getTexture()->getSize();
            float scaleX = 64 / static_cast<float>(texSize.x);
            float scaleY = 64 / static_cast<float>(texSize.y);
            s.setScale(scaleX, scaleY);
            window.draw(s);
        }
};