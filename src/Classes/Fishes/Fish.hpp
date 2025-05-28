#pragma once

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <string>
#include <vector>

class Fish // declaring a Fish class
{
    private:
        sf::Sprite sprite; // sprite of the fish
        std::string name; // name/type of the fish
        std::vector<std::string> location; // where it can be caught
        std::string difficulty; // difficulty to catch
        std::vector<std::string> season; // season(s) where it can be caught
        std::vector<std::string> timeOfDay; // Morning, Noon (maybe), Afternoon, Night 
        std::vector<std::string> weather; // the weahter where it can be caught
        int weight; // weight of the fish
    public:
        Fish() {} // constructor
        ~Fish() {} //deconstructor
        //************************
        //getters and setters
        sf::Sprite getSprite() {return sprite;}
        void setSprite(sf::Sprite s) {sprite = s;}
        std::string getName() {return name;}
        void setName(std::string n) {name = n;}
        std::vector<std::string> getLocation() {return location;}
        void setLocation(std::vector<std::string> l) {location = l;}
        std::string getDifficulty() {return difficulty;}
        void setDifficulty(std::string d) {difficulty = d;}
        std::vector<std::string> getSeason() {return season;}
        void setSeason(std::vector<std::string> seas) {season = seas;}
        std::vector<std::string> getTimeOfDay() {return timeOfDay;}
        void setTimeOfDay(std::vector<std::string> t) {timeOfDay = t;}
        std::vector<std::string> getWeather() {return weather;}
        void setWeather(std::vector<std::string> w) {weather = w;}
        int getWeight() {return weight;}
        void setWeight(int w) {weight = w;}
};