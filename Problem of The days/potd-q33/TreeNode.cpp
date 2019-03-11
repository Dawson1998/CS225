#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* t) {

    // Your code here
    TreeNode * left = t->left_;
    TreeNode * temp = left->right_;
    t->left_ = temp;
    temp->parent_=t;
    left ->right_ = t;
    left->parent_=NULL;
    t->parent_=left;

}


void leftRotate(TreeNode* t) {

    // your code here
    TreeNode * right = t->right_;
    TreeNode * temp = right->left_;
    t->right_ = temp;
    temp->parent_=t;
    right ->left_ = t;
    right->parent_=NULL;
    t->parent_=right;

}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
