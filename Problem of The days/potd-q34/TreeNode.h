#pragma once

#include <cstddef>
#include <algorithm>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
    }

    enum RotationType {
      right, left, rightLeft, leftRight
    };
};

TreeNode::RotationType balanceTree(TreeNode*& subroot);

bool leftHeavy(const TreeNode* subroot);
bool rightHeavy(const TreeNode* subroot);
int getHeight(const TreeNode* root);
void printTreePreOrder(const TreeNode* subroot);
void printRotationType(TreeNode::RotationType rt);
void deleteTree(TreeNode*& subroot);
bool isLeaf(const TreeNode * const subroot);
