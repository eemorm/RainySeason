// Custom Includes
#include "Plant.hpp"

// Standard Output
#include <iostream>
#include <string>

class Carrot : Plant // defines the Carrot class
{
    private:
        enum class Stage // defines the growth stages for this particular Carrot
        {
            Seed = 0, // first stage, a seed
            Sprout = 2, // second stage, a sprout
            Grown = 6, // third stage, a fully grown carrot ready to be harvested
            Dying // a dead carrot in any stage that has not been watered in the appropriate amount of time
        };
        Stage stage = Stage::Seed; // defines the starting stage
    public:
        Carrot() // constructor
        {
            setType("Carrot"); // set type of plant to carrot
            setDaysToGrow(6); // amount of days a carrot takes to grow
            setWaterAmountNeeded(2); // amount of water a carrot needs to count as fully watered
        }
        ~Carrot() {} // deconstructor
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