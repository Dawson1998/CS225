// Animal.cpp
#include "Animal.h"
#include <iostream>
Animal::Animal(){
  type_="cat";
  food_="fish";
}
Animal::Animal(string type,string food)
{
  type_=type;
  food_=food;
}
void Animal::setType(std::string s)
{
  type_=s;
}
std::string Animal::getType()
{
  return type_;
}
void Animal::setFood(std::string s)
{
  food_=s;
}
std::string Animal::getFood()
{
  return food_;
}
std::string Animal::print()
{
  return "I am a "+type_;
}
