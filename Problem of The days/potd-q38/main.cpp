#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "BTreeNode.h"

std::string convert(BTreeNode* root) {
  std::string s = "|";
  if (root==NULL) return s;
  for (size_t i = 0; i < root->elements_.size(); i++)
    s += std::to_string(root->elements_[i]) + "|";
  return s;
}

int main() {

  /**
   *                | 40 |
   *              /         \
   * | 10 | 20 | 30 |   | 50 | 60 |
   */
  std::vector<int> v0 {40};
  std::vector<int> v1 {10, 20, 30}; std::vector<int> v2 {50, 60};
  BTreeNode root(v0), l(v1), r(v2);
  root.children_.push_back(&l);
  root.children_.push_back(&r);
  root.is_leaf_ = false;

  std::cout << "\t  " << convert(&root) << std::endl;
  for (size_t i = 0; i < root.children_.size(); i++) {
      std::cout << convert(root.children_[i]) << "\t";
  }
  std::cout << std::endl << std::endl;

  bool rem_result = removeFromLeaf(50, &root, 1, 5);
  std::cout << "Is the removal successful? " << (rem_result ? "Yes!" : "No!") << std::endl;
  std::cout << std::endl;

  std::cout << "\t" << convert(&root) << std::endl;
  for (size_t i = 0; i < root.children_.size(); i++) {
      std::cout << convert(root.children_[i]) << "\t";
  }
  std::cout << std::endl;

  return 0;
}
