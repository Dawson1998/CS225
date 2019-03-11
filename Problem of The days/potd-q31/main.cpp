#include <iostream>
#include "TreeNode.h"

using namespace std;

int main() {

  TreeNode * n1 = new TreeNode(8);
  TreeNode * n2 = new TreeNode(5);
  TreeNode * n3 = new TreeNode(13);
  TreeNode * n4 = new TreeNode(11);
  n1->left_ = n2;
  n1->right_ = n3;
  n2->right_ = new TreeNode(7);
  n3->left_ = new TreeNode(10);
  n3->right_ = new TreeNode(14);
  n3->left_->right_ = n4;
  n4->right_ = new TreeNode(12);

  std::cout << "n1.isHeightBalanced() : " << isHeightBalanced(n1) << std::endl;
  std::cout << "n2.isHeightBalanced() : " << isHeightBalanced(n2) << std::endl;
  std::cout << "n3.isHeightBalanced() : " << isHeightBalanced(n3) << std::endl;
  std::cout << "n4.isHeightBalanced() : " << isHeightBalanced(n4) << std::endl;

  deleteTree(n1);
  return 0;

}
