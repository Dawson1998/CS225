#include "List.h"
#include <iostream>

int main() {
  List<int> list;
  list.insertBack(4);
  list.insertBack(5);
  list.insertBack(6);
  list.insertBack(7);
  list.insertBack(8);
  list.insertBack(9);
  list.reverseNth(3);
  std::cout<<list<<std::endl;
  return 0;
}
