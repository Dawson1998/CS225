#include <iostream>
#include <stdlib.h>
#include "TreeNode.h"

int main() {

  TreeNode * n1 = new TreeNode(8);
  TreeNode * n2 = new TreeNode(5);
  TreeNode * n3 = new TreeNode(13);
  TreeNode * n4 = new TreeNode(11);
  n1->left_ = n2;
  n1->right_ = n3;
  n2->left_ = new TreeNode(4);
  n2->right_ = new TreeNode(7);
  n3->left_ = new TreeNode(10);
  n3->right_ = new TreeNode(14);
  n3->left_->right_ = n4;
  n4->right_ = new TreeNode(12);

 std::cout << "Last Unbalanced Node with root 8: " << (findLastUnbalanced(n1))->val_ << std::endl; //should be 10
 std::cout << "Last Unbalanced Node with root 13: " << (findLastUnbalanced(n3))->val_ << std::endl; //should be 10
 std::cout << "Last Unbalanced Node with root 10: " << (findLastUnbalanced(n3->left_))->val_ << std::endl; //should be 10
 std::cout << "Last Unbalanced Node with root 5: " << (findLastUnbalanced(n2))<< std::endl; //should be nil
 std::cout << "Last Unbalanced Node with root 11: " << (findLastUnbalanced(n4))<< std::endl; //should be nil

  deleteTree(n1);
  return 0;

}
