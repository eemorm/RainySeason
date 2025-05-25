//Custom Includes
#include "Item.hpp"

//standard i/o
#include <iostream>
#include <string>

class LettuceItem : Item //defining LettuceItem class
{
    public:
        LettuceItem() //constructor
        {
            setName("Lettuce"); //the item name is lettuce
            setCategory("Plant"); //the lettuce is a type of plant
            setDescription(""); //ADD IN LATER
            setRarity(""); //ADD IN  LATER
            setIsStackable = true; //allowing lettuce to be stacked
            setMaxStackable = 999; //can stack 999 lettuce in one inventory slot
            //setIsSellable = true; not sure if we should add this yet
            //setSellPrice = 4; ^^
            //setIsTradable = true;
            //setTradeReward = ("");
        }

        ~LettuceItem() {} //deconstructor
};