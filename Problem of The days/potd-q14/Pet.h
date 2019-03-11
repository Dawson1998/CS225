// Pet.h
#pragma once
#include <iostream>
#include "Animal.h"

class Pet: public Animal
{
public:
  //std::string type_;
  //std::string food;
  Pet();
  Pet(std::string t, std::string f, std::string n, std::string o);
  std::string print();
  void setOwnerName(std::string o);
  void setName(std::string n);
  std::string getName();
  std::string getOwnerName();
private:
  std::string name_;
  std::string owner_name_;
};
