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
            if (items.size() + 1 <= capacity) // if there is space in the inventory
            {
                items.insert(items.begin() + index, newItem); // insert the item at the given index
            }
        }
        void addItem(Item& newItem) // adds newItem to the end of the list
        {
            for (Item& item : items) // for item in items, using pass by reference
            {
                if (item.getName() == newItem.getName() && item.getIsStackable()) // if they are the same item and can stack
                {
                    item.setCurrentStack(item.getCurrentStack() + 1); // stack the items
                    return; // return to end the function
                }
            }
            // if cannot stack
            newItem.setCurrentStack(1); // start a new stack before checking if there is space
            if (items.size() + 1 <= capacity) // if there is space in the inventory
            {
                items.push_back(newItem); // add the item to the inventory
            }
        }
        void removeItem(int index) // removes item at certain index from the list
        {
            items[index].setCurrentStack(items[index].getCurrentStack() - 1); // erase 1 item

            if (items[index].getCurrentStack() <= 0) // if item stack is no more
            {
                items.erase(items.begin() + index); // fully remove the stack from the inventory
            }
        }
        void removeItemStack(int index) // removes item stack at certain index from the list
        {
            items.erase(items.begin() + index); // erase item stack
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