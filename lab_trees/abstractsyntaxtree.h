/**
 * @file abstractsyntaxtree.h
 * Declaraction of the AbstractSyntaxTree class, which inherits
 * BinaryTree<std::string>. This tree is a type of binary tree used
 * to compute syntactical expressions. In this case, we will be
 * evaluating PEMDAS, except we will not have to handle exponential calculations.
 */

#pragma once

#include "binarytree.h"

#include <string>

class AbstractSyntaxTree
: public BinaryTree<std::string>
{
    public:
        /**
         * Constructor that takes in a root node representing the
         * pre-constructed AST.
         * @param node The root node of the preconstructed tree
         * we want to wrap as an Abstract Syntax Tree
         */
        AbstractSyntaxTree(AbstractSyntaxTree::Node* node);

        /**
         * Calculates the value from an AST (Abstract Syntax Tree).
         */
        double eval() const;
        double eval(Node* root) const;
    private:
        // You may add any helper functions you like.....
};

#include "abstractsyntaxtree_given.cpp"
#include "abstractsyntaxtree.cpp"
