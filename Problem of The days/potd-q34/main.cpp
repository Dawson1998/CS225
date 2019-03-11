#include <iostream>
#include <stdlib.h>
#include "TreeNode.h"

int main() {

  TreeNode * n4 = new TreeNode(4);
  TreeNode * n7 = new TreeNode(7);
  TreeNode * n11 = new TreeNode(11);
  TreeNode * n13 = new TreeNode(13);
  TreeNode * n14 = new TreeNode(14);
  TreeNode * n22 = new TreeNode(22);

  n14->left_ = n11;
  n14->right_ = n22;
  n11->right_ = n13;
  n11->left_ = n7;
  n7->left_ = n4;

  TreeNode* root = n14;

  std::cout << "Unbalanced AVL Tree:" << '\n';
  printTreePreOrder(root);

  TreeNode::RotationType rt = balanceTree(root);

  std::cout << "\nProper rotation on root: " << '\n';
  printRotationType(rt);

  deleteTree(root);

  return 0;

}
