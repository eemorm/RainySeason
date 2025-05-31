#pragma once

//Custom Includes
#include "PlaceableItem.hpp"
#include "Textures/Textures.hpp"
#include "Classes/Plants/Plant.hpp"
#include "Classes/Entities/World-Placed/Garden/PlantBedEntity.hpp"
#include "Classes/Entities/World-Placed/PlaceableEntity.hpp"
#include "Global/Global.hpp"

//standard Libraries
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class PlantBedItem : public PlaceableItem //defining PlantBedItem class
{
    private:
        sf::Vector2f size;
    public:
        PlantBedItem(sf::Vector2f s) //constructor
        {
            sf::Sprite tempSprite;
            tempSprite.setTexture(carrotsproutTexture);
            setSprite(tempSprite);
            setName("Plant Bed"); //the item name is plant bed
            setCategory("Garden"); //the plant bed is in a garden I guess?
            setDescription(""); //ADD IN LATER
            setRarity(""); //ADD IN  LATER
            setIsStackable(true); //allowing plant beds to be stacked
            //setIsSellable = true; not sure if we should add this yet
            //setSellPrice = 4; ^^
            //setIsTradable = true;
            //setTradeReward = ("");
            setIsPlaceable(true); // allow plant bed to be placed
            size = s;
        }
        ~PlantBedItem() {} //deconstructor
        //********************
        std::unique_ptr<PlaceableEntity> place(sf::Vector2f mousePos) override { return std::make_unique<PlantBedEntity>(size, mousePos); }
};