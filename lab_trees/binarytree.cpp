/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
#include <stack>
#include <vector>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
 template <typename T>
void BinaryTree<T>::mirror(Node * &s)
{
 //your code here
 if(s==NULL)
 {
   return;
 }
 //std::cout<<"pass1";
 if(s->left!=NULL)
  mirror(s->left);
//std::cout<<"pass2";
if(s->right!=NULL)
  mirror(s->right);
//std::cout<<"pass3";
 Node* temp = s->left;
 s->left = s->right;
 s->right = temp;
 //std::cout<<"pass4";

}
  template <typename T>
void BinaryTree<T>::mirror()
{
    mirror(root);
}


/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
  Node * t = NULL;
  InorderTraversal<T> in(this->getRoot());
  for(TreeTraversal<int>::Iterator i = in.begin(); i != in.end(); ++i){
    if(t == NULL){
      t = *i;
    }
    if(t->elem > (*i)->elem){
      return false;
    }
    if(t->elem < (*i)->elem || t->elem == (*i)->elem){
      t = *i;
    }
  }
  return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    Node *prev = NULL;
    return isOrderedRecursive(root, prev);
    //return false;
}
template <typename T>
/*bool BinaryTree<T>::isBST(Node* root) const
{
    static Node* prev;
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;

        // Allows only distinct valued nodes
        if (prev != NULL && root <= prev)
          return false;

        prev = root;

        return isBST(root->right);
    }

    return true;
}*/
bool BinaryTree<T>::isOrderedRecursive( Node* subRoot,Node *&prev) const
{
  if(subRoot != NULL){
    if(!isOrderedRecursive(subRoot->left, prev)){
      return false;
    }
    if(prev != NULL && subRoot->elem <= prev->elem){
      return false;
    }

    prev = subRoot;

    return isOrderedRecursive(subRoot->right, prev);
  }
  return true;
}


/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::getPaths(std::vector<std::vector<T>>& paths) const
{
    // your code here
    std::vector<T> temp{};
    getPaths(paths,root, temp);
}
template <typename T>
void BinaryTree<T>::getPaths(std::vector<std::vector<T>>& paths,const Node*s,std::vector<T> temp)const
{
    // your code here
    if(s==NULL)
    {
      return;
    }
        temp.push_back(s->elem);
    if(s->left==NULL && s->right==NULL)
    {
      paths.push_back(temp);
    }
    getPaths(paths,s->left,  temp);
    getPaths(paths,s->right, temp);
}


/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    int sum = 0;
  sumDistances(root->left, sum);
  sumDistances(root->right, sum);
  return sum;
}
template <typename T>
int BinaryTree<T>::sumDistances(const Node* subRoot, int &sum) const
{
  int height = 0;
  if(subRoot == NULL){
    return 0;
  }

  int left = sumDistances(subRoot->left, sum);
  int right = sumDistances(subRoot->right, sum);
  height = height + left + right + 1;

  sum = sum + height;
  return height;
}
