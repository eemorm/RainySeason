#pragma once

// Custom Includes
#include "Classes/Entities/World-Placed/PlaceableEntity.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <vector>
#include <memory>

inline std::vector<std::unique_ptr<PlaceableEntity>> placedEntities;