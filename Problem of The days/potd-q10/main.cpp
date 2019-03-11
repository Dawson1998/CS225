#include <iostream>
#include "Base.h"
#include "Derived.h"

int main() {
    Base *x1 = new Base();
    Base *x2 = new Derived();
    Derived *y1 = new Derived();

    std::cout << x1->foo() << std::endl;
    std::cout << x2->foo() << std::endl;
    std::cout << y1->foo() << std::endl;
    std::cout << x1->bar() << std::endl;
    std::cout << x2->bar() << std::endl;
    std::cout << y1->bar() << std::endl;

    delete x1;
    delete x2;
    delete y1;
}
