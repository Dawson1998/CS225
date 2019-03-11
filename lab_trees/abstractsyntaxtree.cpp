#include "abstractsyntaxtree.h"

/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
double AbstractSyntaxTree::eval() const {
    // @TODO Your code goes here...
    Node* a = getRoot();
    return eval(a);
    //return -1;
}
double AbstractSyntaxTree::eval(Node*root) const {
    // @TODO Your code goes here...
    if (!root)
        return 0;
    //std::cout<<root->elem<<"--------------------------------------------------------------------------------";
    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return std::stoi(root->elem);

    // Evaluate left subtree
    double l_val = eval(root->left);

    // Evaluate right subtree
    double r_val = eval(root->right);

    // Check which operator to apply
    if (root->elem=="+")
        return l_val+r_val;

    if (root->elem=="-")
        return l_val-r_val;

    if (root->elem=="*")
        return l_val*r_val;

    return l_val/r_val;
    //return -1;
}
