#include <iostream>
#include "Pet.h"

using namespace std;

int main() {
    Pet p;
    cout << "Name: " << p.getName() << endl;
    cout << "Birth year: " << p.getBY() << endl;
    cout << "Type: " << p.getType() << endl;
    cout << "Owner: " << p.getOwnerName() << endl;
}
