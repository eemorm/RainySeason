#pragma once

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <string>
#include <cmath>

class Player // player class
{
    private:
        sf::Sprite sprite; // current player sprite
        float speed = 100.f; // max speed that the player can reach
        sf::Vector2f velocity; // current player velocity
    public:
        Player() 
        {
            sf::Texture texture;
            sf::Image image;

            // Make a 1x1 image of a color
            image.create(1, 1, sf::Color::Green);
            texture.loadFromImage(image);

            sprite.setTexture(texture);
            sprite.setScale(32.f, 32.f); // Make it 32x32
            sprite.setPosition(0.f, 0.f);
        } // constructor
        ~Player() {} // deconstructor
        // ********************
        sf::Vector2f getPosition()
        {
            return sprite.getPosition();
        }
        void handleInput() 
        {
            velocity = {0.f, 0.f}; // set initial velocity
        
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) velocity.y -= 1.f;     // checks
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) velocity.y += 1.f;     // if
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) velocity.x -= 1.f;     // keys
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) velocity.x += 1.f;     // pressed
        
            // normalize diagonal movement by dividing by root 2...will move 1 unit instead of 1.4
            if (velocity.x != 0.f && velocity.y != 0.f)
            {
                velocity /= std::sqrt(2.f);
            }
        }
        void update(float deltaTime) // updates player position every frame
        {
            sprite.move(velocity * speed * deltaTime);
        }
        void render(sf::RenderWindow &window) // renders the player
        {
            window.draw(sprite);
        }
};