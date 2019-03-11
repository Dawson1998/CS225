// main.cpp

#include "Pet.h"
#include <iostream>
#include <string>

int main() {
    Pet p("cat","fish","Garfield","John");

    std::cout << Animal(p).print() << std::endl;
    std::cout << p.print() << std::endl;
}
