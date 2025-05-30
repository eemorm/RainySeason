#pragma once

//Custom Includes
#include "Item.hpp"
#include "Textures/Textures.hpp"
#include "Classes/Plants/Plant.hpp"

//standard Libraries
#include <iostream>
#include <string>

class PlantBedItem : public Item //defining PlantBedItem class
{
    private:
        Plant plant;
        sf::Vector2f size;
        int rotation;
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
            setIsPlaceable(true);
            size = s;
        }
        ~PlantBedItem() {} //deconstructor
        // ********************
        sf::Vector2f getSize() { return size; }       // getters
        void setSize(sf::Vector2f s) { size = s; }    // and
        int getRotation() { return rotation; }        // setters
        void setRotation(int r) { rotation = r; }
        Plant getPlant() { return plant; }
        void setPlant(Plant p) { plant = p; }
        // ********************
        void rotateClockwise() { rotation = (rotation + 90) % 360; }
        void rotateCounterClockwise() { rotation = (rotation + 270) % 360; }
};