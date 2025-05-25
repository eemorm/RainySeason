#pragma once
// Custom Includes
#include "Plant.hpp"

// Standard Output
#include <iostream>
#include <string>

class Potato : Plant // defines the Potato class
{
    private:
        enum class Stage // defines the growth stages for this particular Potato
        {
            Seed = 0, // first stage, a seed,
            Sprout = 3, // second stage, a sprout,
            Tuber = 5, // third stage, a tuber,
            Grown = 8, // fourth stage, a fully grown potato ready to be harvested,
            Dying // a dead Potato in any stage that has not been watered in the appropriate amount of time
        };
        Stage stage = Stage::Seed; // defines the starting stage
    public:
        Potato() // constructor
        {
            setType("Potato"); // set type of plant to Potato
            setDaysToGrow(8); // amount of days a Potato takes to grow
            setWaterAmountNeeded(1); // amount of water a Potato needs to count as fully watered
        }
        ~Potato() {} // deconstructor
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
