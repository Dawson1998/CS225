#include "TreeNode.h"
#include <iostream>
int height(TreeNode* root)
{
  if(root==NULL)
  {
    return 0;
  }
  int a =1+height(root->right_);
  int b =1+height(root->left_);
  if(a>b)
  {
    return a;
  }
  return b;
}
bool isHeightBalanced(TreeNode* root) {
  // your code here
  if(root->left_==NULL && root->right_==NULL)
  {
    return true;
  }
  int a = height(root->right_);
  int b2 = height(root->left_);
  int b = a-b2;
  if (b==0||b==-1||b==1)
  {
    return true;
  }
  return false;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
