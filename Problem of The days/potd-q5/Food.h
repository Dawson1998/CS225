// Your code here
#ifndef FOOD_H
#define FOOD_H
#include <iostream>
using namespace std;
class Food {
  private:
    string name_;
    int quantity_;
  public:
    Food();
    string get_name();
    void set_name(string n);
    int get_quantity();
    void set_quantity(int q);
};

#endif
