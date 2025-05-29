#pragma once

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
        sf::Sprite sprite;
        int quantity;
        sf::RectangleShape background;
        float size = 64.0f;
        sf::Vector2f position;
    public:
        Slot() 
        {
            background.setSize(sf::Vector2f(size, size));
            sprite.setScale(sf::Vector2f(size, size));
            background.setFillColor(sf::Color(100, 100, 100, 200));
            background.setOutlineColor(sf::Color::White);
            background.setOutlineThickness(2);
        }
        ~Slot() {}
        // ********************
        sf::Sprite& getSprite() { return sprite; }
        void setSprite(sf::Sprite s) { sprite = s; }
        int getQuantity() { return quantity; }
        void setQuantity(int q) { quantity = q; }
        sf::RectangleShape getBackground() { return background; }
        void setBackground(sf::RectangleShape b) { background = b; }
        float getSize() { return size; }
        void setSize(float s) { size = s; }
        sf::Vector2f getPosition() { return position; }
        void setPosition(sf::Vector2f p) { position = p; background.setPosition(position); sprite.setPosition(position); }
};