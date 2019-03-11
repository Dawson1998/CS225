#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  if(rightHeavy(subroot))
  {
    if(rightHeavy(subroot->right_))
    {
      return TreeNode::left;
    }
    else
    {
      return TreeNode::rightLeft;
    }
  }
  if(leftHeavy(subroot))
  {
    if(leftHeavy(subroot->left_))
    {
      return TreeNode::right;
    }
    else
    {
      return TreeNode::leftRight;
    }
  }
  return TreeNode::right;
}
