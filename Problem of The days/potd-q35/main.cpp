#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "BTreeNode.h"

std::string convert(BTreeNode* root) {
  std::string s = "";
  if (root==NULL) return s;
  for (size_t i=0; i<root->elements_.size(); i++)
    s += std::to_string(root->elements_[i]) + " ";
  return s;
}

int main() {
  std::vector<int> v1 {30, 60}; std::vector<int> v2 {10, 20}; 
  std::vector<int> v3 {40, 50}; std::vector<int> v4 {70, 80};
  BTreeNode n_0(v1), n_2(v2), n_3(v3), n_4(v4);
  n_0.children_.push_back(&n_2); 
  n_0.children_.push_back(&n_3);
  n_0.children_.push_back(&n_4);
  
  n_0.is_leaf_ = false;
  BTreeNode* ans;
  ans = find(&n_0, 110);
  std::string found = (ans != NULL? "Yes :) In Node    ":"No. ");
  std::cout << "find(root, 110):  Was found? " << std::endl<< found << convert(ans) << " " <<std::endl<<std::endl;;

  ans = find(&n_0, 80);
  found = (ans != NULL? "Yes :) In Node    ":"No. ");
  std::cout << "find(root, 80):  Was found? " << std::endl<< found << convert(ans) << " " <<std::endl<<std::endl;

  ans = find(&n_0, 10);
  found = (ans != NULL? "Yes :) In Node    ":"No. ");
  std::cout << "find(root, 10):  Was found? " << std::endl<< found << convert(ans) << " " <<std::endl<<std::endl;

  ans = find(&n_0, 30);
  found = (ans != NULL? "Yes :) In Node    ":"No. ");
  std::cout << "find(root, 30):  Was found? " << std::endl<< found << convert(ans) << " " <<std::endl<<std::endl;

  return 0;
}

