#pragma once

// Custom Includes
#include "Fish.hpp"

// Standard Libraries
#include <iostream>
#include <string>

// for the random function to generate a random weight
#include <cstdlib>
#include <ctime>

class Salmon : public Fish // declaring salmon class
{   
    public:
        Salmon() // constructor
        {
            setName("Salmon"); // setting name to Salmon
            setLocation({"River", "Ocean"}); // can be found in rivers and oceans
            setDifficulty("Easy"); // easy to catch
            setSeason({"Fall"}); // can be caught in fall
            setTimeOfDay({"Morning", "Afternoon"}); // can be caught morning or afternoon
            setWeather({"Cloudy", "Raining"}); // can be caught when cloudy or raining
        }
        ~Salmon() {} // deconstructor
        //**************************
        void generateRandomWeight()
        {
            // seeding random number generator 
            srand(time(0));
            // generating random number
            int randomNumber = 8 + (rand() % (12 - 8 + 1));
            // setting weight to the random number
            setWeight(randomNumber);
        }
};