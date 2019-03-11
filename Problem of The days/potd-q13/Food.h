#pragma once

#include <iostream>
#include <string>

class Food {
  private:
    std::string name_;
    int quantity_;
  public:
    Food();
    void setName(std::string newName);
    void setQuantity(int newQuantity);
    std::string getName() const;
    int getQuantity() const;
    bool operator>(const Food & that) const;
    //const Food &   operator> (const Food &other)
};
