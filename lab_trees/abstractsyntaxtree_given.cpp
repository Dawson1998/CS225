#include "abstractsyntaxtree.h"

AbstractSyntaxTree::AbstractSyntaxTree(AbstractSyntaxTree::Node* node) 
    : BinaryTree<std::string>(node)
{ /* nothing */
}
