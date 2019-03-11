#include <iostream>

#include "Animal.h"

int main() {
  Animal a;
  std::cout<<"Default constructor:"<<std::endl;
  std::cout<<"  Type: "<<a.getType()<<", Food: "<<a.getFood()<<std::endl;
  std::cout << a.print() << std::endl;
  std::cout<<std::endl;

  Animal b("horse", "hay");
  std::cout<<"Two parameter constructor:"<<std::endl;
  std::cout<<"  Type: "<<b.getType()<<", Food: "<<b.getFood()<<std::endl;
  std::cout << b.print() << std::endl;
  std::cout<<std::endl;

  b.setType("snake");
  b.setFood("mouse");
  std::cout<<"After using setters:"<<std::endl;
  std::cout<<"  Type: "<<b.getType()<<", Food: "<<b.getFood()<<std::endl;
  std::cout << b.print() << std::endl;
  std::cout<<std::endl;

  return 0;
}
