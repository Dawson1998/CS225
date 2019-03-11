#include <iostream>
#include <string>

#include "Food.h"
#include "potd.h"

int main() {
    Food apples, oranges, greater;
    apples.setName("apples");
    apples.setQuantity(5);
    oranges.setName("oranges");
    oranges.setQuantity(3);
    greater = more<Food>(apples, oranges);
    std::cout << "We have more " << greater.getName() << "." << std::endl;
    return 0;
}
