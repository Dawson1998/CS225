#include <vector>
#include "BTreeNode.h"
#include <iostream>


std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    return traverse(root,&v);
}
std::vector<int> traverse(BTreeNode* root, std::vector<int>* v)
{
  unsigned i = 0;
  while(i<root->elements_.size())
  {
    if(!root->is_leaf_)
    {
      //std::cout<<"hi";
      traverse(root->children_[i],v);
    }
    v->push_back(root->elements_[i]);
    i++;
  }
  if(!root->is_leaf_)
  {
    traverse(root->children_[i],v);
  }
  return *v;
}
