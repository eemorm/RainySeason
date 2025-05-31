//Custom Includes
#include "Item.hpp"
#include "Classes/Entities/World-Placed/PlaceableEntity.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Libraries
#include <iostream>
#include <string>
#include <memory>

class PlaceableItem : public Item
{
    public:
        virtual std::unique_ptr<PlaceableEntity> place(sf::Vector2f mousePos) { return nullptr; }
};