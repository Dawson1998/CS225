// Animal.h
#pragma once
#include <iostream>
#include <string>

using namespace std;
class Animal
{
public:
  Animal();
  Animal(string type, string food);
  string food_;
  void setType(string);
  string getType();
  void setFood(string);
  string getFood();
  string print();
private:
  string type_;
};
