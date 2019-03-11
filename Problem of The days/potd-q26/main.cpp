#include <iostream>
using namespace std;

#include "Stack.h"

int main() {
  Stack s;
  int r;

  cout<<"push(3) to the stack..."<<endl;
  s.push(3);
  cout<<"Stack size: "<<s.size()<<endl;

  cout<<"push(2) to the stack..."<<endl;
  s.push(2);
  cout<<"Stack size: "<<s.size()<<endl;

  cout<<"push(1) to the stack..."<<endl;
  s.push(1);
  cout<<"Stack size: "<<s.size()<<endl;


  cout<<"pop()"<<endl;
  r = s.pop();
  cout<<"Returned Value: "<<r<<", Stack size: "<<s.size()<<endl;

  cout<<"pop()"<<endl;
  r = s.pop();
  cout<<"Returned Value: "<<r<<", Stack size: "<<s.size()<<endl;

  cout<<"pop()"<<endl;
  r = s.pop();
  cout<<"Returned Value: "<<r<<", Stack size: "<<s.size()<<endl;

  return 0;
}
