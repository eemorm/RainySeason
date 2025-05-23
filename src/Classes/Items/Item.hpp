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

class Item //defining the class Item
{
    private:
        sf:Sprite sprite; //sprite of the item
        std::string name; //name of the item
        std::string category; //i.e., food, tool, furniture, etc.
        std::string description; //description can be displayed in-game
        std::string rarity; //might need to be changed if we do stars or smth
        bool isStackable; //whether the item is stackable
        int maxStackable; //if it is stackable, what the max stacking is

        if (!isStackable) //if it isn't stackable, then you can only stack up to 1
        {
            maxStackable = 1;
        }

        bool isSellable; //whether the item can be sold
        if (isSellable) {int sellPrice;} //price if it can be sold
        bool isTradable; //whether it can be traded
        if (isTradable) {std:string tradeReward} //what you get in return for trading
    //****we might not end up implementing isSellable or isTradable!****
    public:
        Item() {} //constructer?
        ~Item () {} //deconstructer???

        //all of the following are setters and getters
        sf::Sprite getSprite() {return sprite;}
        void setSprite(sf:Sprite s) {sprite = s;}
        std::string getName() {return name;}
        void setName(std:string n) {name = n;}
        std::string getCategory() {return category;}
        void setCategory(std::string c) {category = c;}
        std::string getDescription() {return description;}
        void setDescription(std::string d) {description = d;}
        std::string getRarity() {return rarity;}
        void setRarity(std::string r) {rarity = r;}
        bool getIsStackable() {return isStackable;}
        void setIsStackable(bool istk) {isStackable = is;}
        int getMaxStackable() {return maxStackable;}
        void setMaxStackable(int ms) {maxStackable = ms;}
        bool getIsSellable() {return isSellable;}
        void setIsSellable(bool isll) {isSellable = isll;}

        if (isSellable) //only do setters and getters for the sell price if it can be sold
        {
            int getSellPrice() {return sellPrice;}
            void setSellPrice(int sp) {sellPrice = sp;} 
        }

        bool getIsTradable() {return isTradable;}
        void setIsTradable(bool it) {isTradable = it;}
        
        if (isTradable) //only do trading mechanics if it can be traded
        {
            std::string getTradeReward() {return tradeReward;}
            void setTradeReward(std::string tr) {tradeReward = tr;}
        }
}
