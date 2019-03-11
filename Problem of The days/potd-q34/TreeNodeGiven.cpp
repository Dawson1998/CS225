#include "TreeNode.h"

bool leftHeavy(const TreeNode* subroot) {
  if (subroot == NULL) {
    return false;
  }
  int lHeight = getHeight(subroot->left_);
  int rHeight = getHeight(subroot->right_);

  return lHeight > rHeight;
}

bool rightHeavy(const TreeNode* subroot) {
  if (subroot == NULL) {
    return false;
  }
  int lHeight = getHeight(subroot->left_);
  int rHeight = getHeight(subroot->right_);

  return rHeight > lHeight;
}

int getHeight(const TreeNode* subroot) {
  if (subroot == NULL) {
    return -1;
  }
  return (1 + std::max(getHeight(subroot->left_), getHeight(subroot->right_)));
}

void printTreePreOrder(const TreeNode* subroot) {
  TreeNode* left = subroot->left_;
  TreeNode* right = subroot->right_;
  std::cout << subroot->val_ << '\t';
  if (left) {
    printTreePreOrder(left);
  }
  if (right) {
    printTreePreOrder(right);
  }
}

void printRotationType(TreeNode::RotationType rt) {
    switch (rt) {
        case TreeNode::right:
            std::cout << "Right" << std::endl;
            break;

        case TreeNode::left:
            std::cout << "Left" << std::endl;
            break;

        case TreeNode::rightLeft:
            std::cout << "Right Left" << std::endl;
            break;

        case TreeNode::leftRight:
            std::cout << "Left Right" << std::endl;
            break;

        default:
            break;
    }
}

void deleteTree(TreeNode*& subroot)
{
  if (subroot == NULL) return;
  deleteTree(subroot->left_);
  deleteTree(subroot->right_);
  delete subroot;
  subroot = NULL;
}

bool isLeaf(const TreeNode * const subroot) {
  return subroot->left_ == NULL && subroot->right_ == NULL;
}
