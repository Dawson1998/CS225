#pragma once

#include <string>

class Animal {
    private:
        std::string type_;
    protected:
        std::string food_;
    public:
        Animal();
        Animal(std::string type, std::string food);

        void setFood(std::string nu_food);
        std::string getFood();
        void setType(std::string nu_type);
        std::string getType();
        std::string print();
};
