#pragma once

// Custom Includes
#include "Classes/Inventory/Slot.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <vector>

extern std::vector<Slot> slots;
extern sf::Font font;
static int selectedSlotIndex = -1;

std::vector<sf::Vector2f> calculateSlotPositions(
    int screenWidth,
    int screenHeight,
    int numSlots,
    float slotSize,
    float slotSpacing,
    float edgeSpacing
);

void initializeInventoryVisual(
    int screenWidth,
    int screenHeight,
    int numSlots,
    float slotSize,
    float slotSpacing,
    float edgeSpacing
);

void updateInventoryVisual();

std::vector<Slot>& getSlots();