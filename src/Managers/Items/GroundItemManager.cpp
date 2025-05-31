// Custom Includes
#include "Classes/Items/GroundItem.hpp"
#include "Classes/Items/CarrotItem.hpp"
#include "Classes/Items/PlantBedItem.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Libraries
#include <iostream>
#include <vector>

std::vector<GroundItem> groundItems;

void setTestGroundItems()
{
    groundItems.push_back(GroundItem(CarrotItem(), {100, 100}));
    groundItems.push_back(GroundItem(PlantBedItem({1, 1}), {300, 300}));
}
