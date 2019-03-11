// Animal.cpp
#include <iostream>
#include <string>
#include "Animal.h"

void Animal::setFood(std::string nu_food) {
    food_ = nu_food;
}

std::string Animal::getFood() {
    return food_;
}

void Animal::setType(std::string nu_type) {
    type_ = nu_type;
}

std::string Animal::getType() {
    return type_;
}

std::string Animal::print() {
    return "I am a " + type_;
};

Animal::Animal() : type_("cat"), food_("fish") { }

Animal::Animal(std::string type, std::string food) : type_(type), food_(food) { }
