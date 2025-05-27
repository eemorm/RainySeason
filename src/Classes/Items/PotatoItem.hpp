//Custom Includes
#include "Item.hpp"

//standard i/o
#include <iostream>
#include <string>

class PotatoItem : Item //defining PotatoItem class
{
    public:
        PotatoItem() //constructor
        {
            setName("Potato"); //the item name is potato
            setCategory("Plant"); //the potato is a type of plant
            setDescription(""); //ADD IN LATER
            setRarity(""); //ADD IN  LATER
            setIsStackable(true); //allowing potatoes to be stacked
            setMaxStackable(999); //can stack 999 potatoes in one inventory slot
            //setIsSellable = true; not sure if we should add this yet
            //setSellPrice = 4; ^^
            //setIsTradable = true;
            //setTradeReward = ("");
        }

        ~PotatoItem() {} //deconstructor
};