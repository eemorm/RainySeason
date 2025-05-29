#pragma once

//Custom Includes
#include "Classes/Items/Item.hpp"
#include "Managers/Items/GroundItemManager.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <string>
#include <vector>

class Inventory // declaring inventory class
{
    private:
        std::vector<Item> items; // declaring list of items of type Item class
        int capacity; // max amount of items that can be held, i.e. amount of slots
    public:
        Inventory(int c) // constructor
        {
            capacity = c;
        }
        ~Inventory() {} // deconstructor
        // ********************
        // setters and getters
        std::vector<Item>& getItems() {return items;} // returns list of items
        void setItems(std::vector<Item> i) {items = i;} // sets items in the inventory
        int getCapacity() {return capacity;} // returns capacity of the inventory
        void setCapacity(int c) {capacity = c;} // sets capacity to c
        // ********************
        // following functions are for dealing with items in the inventory
        void insertItem(Item newItem, int index) // adds newItem to the list at index 
        {
            if (items.size() + 1 <= capacity)
            {
                items.insert(items.begin() + index, newItem);
            }
        }
        void addItem(Item& newItem) // adds newItem to the end of the list
        {
            for (Item& item : items)
            {
                if (item.getName() == newItem.getName() && item.getIsStackable())
                {
                    item.setCurrentStack(item.getCurrentStack() + 1);
                    return;
                }
            }
            newItem.setCurrentStack(1);
            if (items.size() + 1 <= capacity)
            {
                items.push_back(newItem);
            }
        }
        void removeItem(int index) // removes item at certain index from the list
        {
            items.erase(items.begin() + index);
        }
        void dropItem(int index, sf::Vector2f dropPosition) // drops item from the inventory
        {
            GroundItem groundItem; // set temporary item to add to the list

            groundItem.setItem(items[index]);         // set
            groundItem.setPosition(dropPosition);     // values

            groundItems.push_back(groundItem); // push back item to ground items
            removeItem(index); // remove item from inventory
        }
        
}; 