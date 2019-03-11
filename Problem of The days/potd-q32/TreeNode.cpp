#include "TreeNode.h"
#include <iostream>
void find(TreeNode *root, int level, int &maxLevel, TreeNode *&res) 
{ 
    if (root != NULL) 
    { 
        find(root->left_, ++level, maxLevel, res); 
  
        // Update level and resue 
        if (level > maxLevel) 
        { 
            res = root; 
            maxLevel = level; 
        } 
  
        find(root->right_, level, maxLevel, res); 
    } 
} 
  
// Returns value of deepest node 
TreeNode* deepestNode(TreeNode *root) 
{ 
    // Initialze result and max level 
    TreeNode* res = NULL; 
    int maxLevel = -1; 
  
    // Updates value "res" and "maxLevel" 
    // Note that res and maxLen are passed 
    // by reference. 
    find(root, 0, maxLevel, res); 
    return res; 
} 
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
TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
	if(root->left_==NULL && root->right_==NULL)
  {
    return root;
  }
	if(isHeightBalanced(root)==true)
	{return NULL;}
	return deepestNode(root);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

