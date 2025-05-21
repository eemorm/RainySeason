// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <string>

class Plant // defines the plant class
{
    private:
        sf::Sprite sprite;
        std::string type; // type of plant, such as carrot, potato, etc.
        int daysToGrow; // days the plant takes to grow
        int growthStage = 0; // stage of growth that the plant is on, i.e. daysToGrow - growthStage = days left until harvest
        int waterAmountNeeded; // amount of water needed to satisfy the plant
        int waterLevel = 0; // amount of water that the plant currently has
        bool isHarvestable = false; // if the plant can currently be harvested
        bool isDead = false; // if the plant is dead, missed too large of a watering time
    public:
        Plant() {} // constructor
        ~Plant() {} // deconstructor
        // ********************
        sf::Sprite getSprite() { return sprite; }                          // all
        void setSprite(sf::Sprite s) { sprite = s; }                       // of
        std::string getType() { return type; }                             // these
        void setType(std::string t) { type = t; }                          // are
        int getDaysToGrow() { return daysToGrow; }                         // getters
        void setDaysToGrow(int dtg) { daysToGrow = dtg; }                  // and
        int getGrowthStage() { return growthStage; }                       // setters
        void setGrowthStage(int gs) { growthStage = gs; }
        int getWaterAmountNeeded() { return waterAmountNeeded; }
        void setWaterAmountNeeded(int wan) { waterAmountNeeded = wan; }
        int getWaterLevel() { return waterLevel; }
        void setWaterLevel(int wl) { waterLevel = wl; }
        bool getIsHarvestable() { return isHarvestable; }
        void setIsHarvestable(bool ih) { isHarvestable = ih; }
        bool getIsDead() { return isDead; }
        void setIsDead(bool id) { isDead = id; }
        // ********************
        void harvest() // check if the plant can be harvested and if it can harvest the plant
        {
            if (isHarvestable) // check if harvestable
            {
                growthStage = 0;
                isHarvestable = false;
            }
        }
};