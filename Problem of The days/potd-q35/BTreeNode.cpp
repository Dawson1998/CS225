#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    //int max = 0;
    if(root==NULL)
    {
      return NULL;
    }
    size_t s = 0;
    int i = 0;
    for(s = 0; s<root->elements_.size() && root->elements_[i]<key;s++)
    {
      i++;
    }
    if(key == root->elements_[i])
    {
      return root;
    }
    if(root->children_.empty())
    {
      return NULL;
    }
    return find(root->children_[i],key);


  //return NULL;
}
