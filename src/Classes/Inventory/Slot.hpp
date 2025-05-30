#pragma once

// Custom Includes
#include "Classes/Items/Item.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <vector>

class Slot
{
    private:
        Item item;
        sf::RectangleShape background;
        float size = 64.0f;
        sf::Vector2f position;
    public:
        Slot() 
        {
            background.setSize(sf::Vector2f(size, size));
            background.setFillColor(sf::Color(100, 100, 100, 200));
            background.setOutlineColor(sf::Color::White);
            background.setOutlineThickness(2);
        }    
        ~Slot() {}
        Item& getItem() { return item; }
        const Item& getItem() const { return item; }
        void setItem(Item i) { item = i; }
        sf::RectangleShape getBackground() { return background; }
        void setBackground(sf::RectangleShape b) { background = b; }
        float getSize() { return size; }
        void setSize(float s) { size = s; }
        sf::Vector2f getPosition() { return position; }
        void setPosition(sf::Vector2f p) { position = p; background.setPosition(position); item.getSprite().setPosition(position); }
        // ********************
        bool hasValidSprite() { return item.getSprite().getTexture() != nullptr; }

};