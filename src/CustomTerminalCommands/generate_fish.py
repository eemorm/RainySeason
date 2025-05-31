import os

def to_camel_case(s):
    return s[0].upper() + s[1:]

def main():
    fish_name = input("Enter fish name (e.g., Salmon) ").strip()
    class_name = to_camel_case(plant_name)

    difficulty = input("Enter difficulty to catch: ").strip()
    min_weight = input("Enter the minimum weight of the fish: ").strip()
    max_weight = input("Enter the maximum weight of the fish: ").strip()

    print("\nEnter locations to catch in order (e.g., River). Type 'done' to finish.")
    locations = []
    while True:
        location = input("Location: ")
        if location.lower() == 'done':
            break
        parts = location.strip().split()
        locations.append(parts)

    print("\nEnter seasons when the fish is catchable (e.g., Fall). Type 'done' to finish.")
    seasons = []
    while True:
        season = input("Season: ")
        if season.lower() == 'done':
            break
        parts = season.strip().split()
        season.append(parts)

    print("\nEnter the times of day when the fish is catchable (e.g., Morning, Afternoon). Type 'done' to finish.")
    timesCatchable = []
    while True:
        timeToCatch = input("Time: ")
        if timeToCatch.lower() == 'done':
            break
        parts = timeToCatch.strip().split()
        timesCatchable.append(parts)

    print("\nEnter the types of weather where the fish is catchable (e.g., Cloudy, Raining). Type 'done' to finish.")
    weathers = []
    while True:
        weath = input("Weather: ")
        if weath.lower() == 'done':
            break
        parts = weath.strip().split()
        timesCatchable.append(weath)

    output_dir = os.path.join("src", "Classes", "Fishes")
    os.makedirs(output_dir, exist_ok=True)
    file_path = os.path.join(output_dir, f"{class_name}.hpp")

    content = f"""
    #pragma once

// Custom Includes
#include "Fish.hpp"

// Standard Libraries
#include <iostream>
#include <string>

// for the random function to generate a random weight
#include <cstdlib>
#include <ctime>

class {class_name} : public Fish // declaing {fish_name} class
{{
    public:
        {class_name}() // constructor
        {{
            setName("{fish_name}"); // setting name to {fish_name}
            setLocation({locations}); // can be found in {locations}
            setDifficulty("{difficulty}"); // {difficulty} to catch
            setSeason({seasons}); // can be caught in {seasons}
            setTimeOfDay({timesCatchable}); // can be caught during {timesCatchable}
            setWeather({weathers}); // can be caught when {weathers}
        }}
        ~{class_name}() {{}} // deconstructor
        //**************************
        void generateRandomWeight()
        {{
            // seeding random number generator 
            srand(time(0));
            // generating random number
            int randomNumber = {min_weight} + (rand() % ({max_weight} - {min_weight} + 1));
            // setting weight to the random number
            setWeight(randomNumber);
        }}
}};
"""

    with open(file_path, "w") as f:
        f.write(content)

    print(f"\n✅ Generated: {file_path}")

if __name__ == "__main__":
    main()