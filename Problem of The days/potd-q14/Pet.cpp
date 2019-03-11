// Pet.cpp
#include "Pet.h"
#include <iostream>

Pet::Pet()
{
  name_="Fluffy";
  setFood("fish");
  setType("cat");
  owner_name_="Cinda";
}
Pet::Pet(std::string t, std::string f, std::string n, std::string o)
{
  name_=n;
  setFood(f);
  setType(t);
  owner_name_=o;
}
std::string Pet::print()
{
  return "My name is "+name_;
}
void Pet::setOwnerName(std::string o)
{
  owner_name_=o;
}
void Pet::setName(std::string n)
{
  name_=n;
}
std::string Pet::getName()
{
  return name_;
}
std::string Pet::getOwnerName()
{
  return owner_name_;
}
