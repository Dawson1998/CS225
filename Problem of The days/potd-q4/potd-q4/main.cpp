#include <iostream>
#include "Circle.h"
#include "q4.h"

using namespace std;

int main() {
  Circle c;
  c.setRadius(5);

  Circle *ptr = &c;

  cout<<"In main, the memory address of c is: "<<(&c)<<endl;

  pass_by_value(c);
  pass_by_pointer(ptr);
  pass_by_ref(c);

  return 0;
}
