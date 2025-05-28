#pragma once
// Custom Includes
#include "Plant.hpp"

// Standard Output
#include <iostream>
#include <string>

class Lettuce : public Plant // defines the Lettuce class
{
    private:
        enum class Stage // defines the growth stages for this particular Lettuce
        {
            Seed = 0, // first stage, a seed,
            Seedling = 2, // second stage, a seedling,
            Leafy = 5, // third stage, a leafy,
            Grown = 7, // fourth stage, a fully grown lettuce ready to be harvested,
            Dying // a dead Lettuce in any stage that has not been watered in the appropriate amount of time
        };
        Stage stage = Stage::Seed; // defines the starting stage
    public:
        Lettuce() // constructor
        {
            setType("Lettuce"); // set type of plant to Lettuce
            setDaysToGrow(7); // amount of days a Lettuce takes to grow
            setWaterAmountNeeded(2); // amount of water a Lettuce needs to count as fully watered
        }
        ~Lettuce() {} // deconstructor
        // ********************
        Stage getStage() { return stage; }           // getter
        void setStage(Stage s) { stage = s; }        // setter
        // ********************
        void advanceStage() // advance stage if conditions are correct
        {
            if (stage != Stage::Dying) // check if the plant is not dying
            {
                int currentStageValue = static_cast<int>(stage);

                if (getGrowthDay() >= currentStageValue + 1) // check if passed next requirement and update stage
                {
                    stage = static_cast<Stage>(currentStageValue + 1);
                }
                if (stage == Stage::Grown) // check if the plant is grown and if the plant can be harvested
                {
                    setIsHarvestable(true);
                }
            }
        }
};
