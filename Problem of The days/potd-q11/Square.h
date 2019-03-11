#pragma once

#include <string>

class Square {
    private:
        std::string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(std::string newName);
        void setLength(double newVal);
        std::string getName() const;
        double getLength() const;
        Square & operator=(const Square & other);
        Square operator+(const Square & other);
};
