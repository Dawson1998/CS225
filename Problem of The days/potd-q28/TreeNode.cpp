#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  //int count = 0;
  TreeNode:: TreeNode  *temp;
  temp = this;
  if(this==NULL)
  {
    return -1;
  }
  else
  {
    return 1 + max(this->left_->getHeight(),this->right_->getHeight());
  }
  return -1;
}
