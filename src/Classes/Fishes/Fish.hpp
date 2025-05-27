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

class Fish // declaring a Fish class
{
    private:
        sf::Sprite sprite; // sprite of the fish
        std::string name; // name/type of the fish
        std::string location; // where it can be caught
        std::string difficulty; // difficulty to catch
        std::string season; // season(s) where it can be caught
        std::string time; // the time that it can be caught (i.e., Morning)
        std::string weather; // the weahter where it can be caught
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
        std::string getLocation() {return location;}
        void setLocation(std::string l) {location = l;}
        std::string getDifficulty() {return difficulty;}
        void setDifficulty(std::string d) {difficulty = d;}
        std::string getSeason() {return season;}
        void setSeason(std::string seas) {season = seas;}
        std::string getTime() {return time;}
        void setTime(std::string t) {time = t;}
        std::string getWeather() {return weather;}
        void setWeather(std::string w) {weather = w;}
        int getWeight() {return weight;}
        void setWeight(int w) {weight = w;}
};