#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "BTreeNode.h"

int main() {
  std::vector<int> v1 {30, 60}; std::vector<int> v2 {10, 20}; 
  std::vector<int> v3 {40, 50}; std::vector<int> v4 {70, 80};
  BTreeNode n_0(v1), n_2(v2), n_3(v3), n_4(v4);
  n_0.children_.push_back(&n_2); 
  n_0.children_.push_back(&n_3);
  n_0.children_.push_back(&n_4);
  
  n_0.is_leaf_ = false;
  std::vector<int> tr = traverse(&n_0);
  for (std::vector<int>::const_iterator i = tr.begin(); i != tr.end(); ++i)
          std::cout << *i << ' ';
  std::cout << std::endl;

  return 0;
}

