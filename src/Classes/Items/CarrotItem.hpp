//Custom Includes
#include "Item.hpp"
#include "Textures/Textures.hpp"

//standard i/o
#include <iostream>
#include <string>

class CarrotItem : public Item //defining CarrotItem class
{
    public:
        CarrotItem() //constructor
        {
            sf::Sprite tempSprite;
            tempSprite.setTexture(carrotTexture);
            setSprite(tempSprite);
            setName("Carrot"); //the item name is carrot
            setCategory("Plant"); //the carrot is a type of plant
            setDescription(""); //ADD IN LATER
            setRarity(""); //ADD IN  LATER
            setIsStackable(true); //allowing carrots to be stacked
            setMaxStackable(999); //can stack 999 carrots in one inventory slot
            //setIsSellable = true; not sure if we should add this yet
            //setSellPrice = 4; ^^
            //setIsTradable = true;
            //setTradeReward = ("");
        }

        ~CarrotItem() {} //deconstructor
};