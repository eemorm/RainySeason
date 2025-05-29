// Custom Includes
#include "InventoryUI.hpp"
#include "Classes/Inventory/Slot.hpp"
#include "Textures/Textures.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <vector>

std::vector<Slot> slots;

std::vector<sf::Vector2f> calculateSlotPositions(
    int screenWidth,
    int screenHeight,
    int numSlots,
    float slotSize,
    float slotSpacing,
    float edgeSpacing
) 
{
    std::vector<sf::Vector2f> positions;

    float totalHotbarWidth = slotSize * numSlots + slotSpacing * (numSlots - 1);
    totalHotbarWidth = std::min(totalHotbarWidth, static_cast<float>(screenWidth) - edgeSpacing * 2);
    float startX = (screenWidth - totalHotbarWidth) / 2.0f;
    float y = screenHeight - edgeSpacing - slotSize;

    for (int i = 0; i < numSlots; ++i) 
    {
        float x = startX + i * (slotSize + slotSpacing);
        positions.push_back({x, y});
    }

    return positions;
}

void initializeInventoryVisual(
    int screenWidth,
    int screenHeight,
    int numSlots,
    float slotSize,
    float slotSpacing,
    float edgeSpacing
)
{
    slots.clear(); // Optional: reset if re-initializing
    auto positions = calculateSlotPositions(screenWidth, screenHeight, numSlots, slotSize, slotSpacing, edgeSpacing);

    for (const auto& pos : positions) 
    {
        Slot slot;
        sf::Sprite sprite;
        sprite.setTexture(carrotTexture);
        auto texSize = sprite.getTexture()->getSize();
        float scaleX = slotSize / static_cast<float>(texSize.x);
        float scaleY = slotSize / static_cast<float>(texSize.y);
        sprite.setScale(scaleX, scaleY);
        slot.setSprite(sprite);
        slot.setPosition(pos);
        slots.push_back(slot);
    }
}

std::vector<Slot>& getSlots()
{
    return slots;
}