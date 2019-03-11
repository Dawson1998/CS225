// your code here
#include <iostream>
#include "Food.h"
#include "q5.h"

using namespace std;

int main() {
  Food c;
  Food  * ptr =&c;
  c.set_name("apple");
  c.set_quantity(5);

  cout<<"You have "<<c.get_quantity()<<" "<<c.get_name()<<"s."<<endl;
  increase_quantity(ptr);
  cout<<"You have "<<c.get_quantity()<<" "<<c.get_name()<<"s."<<endl;
  return 0;
}
