#include "BTreeNode.h"
#include <assert.h>
#include <algorithm>
#include <iostream>

/**
 * Check if the given number of elements in a BTree node underflows.
 * @param numElem Number of elements in this node.
 * @param order The order of the BTree.
 * @return True if it underflows, False otherwise.
 */
bool underflows(unsigned numElem, unsigned order) {
    // TODO: Your code here!
    return false;
}

/**
 * Fix the underflow child node at idx by rotating right 
 * (borrowing a node from left sibling).
 * @param idx The underflow child to be fixed is at children_[idx].
 * @return If the rotation can be done.
 */
bool BTreeNode::rotateRight(unsigned idx, unsigned order) {
    /**
     * First check if there is a left sibling.
     * If there is not, simply return false because rotateRight cannot be done.
     */
    if (idx <= 0)   return false;

    /**
     * Then check if the left sibling leaf contains enough elements after one being borrowed.
     */
    BTreeNode* prev = children_[idx - 1];
    if (underflows(prev->elements_.size() - 1, order)) {
        /**
         * If it's not enough, this case cannot be handled by rotateRight.
         * Simply return false.
         */
        return false;
    }
    /**
     * Do the right rotation by stealing one element from left sibling 
     * and fixing the parent key.
     * 
     * Example: Assume we are doing rotateRight around (40) to fix right child
     * (we are in BTreeNode(40), idx = 1 (the second child)),
     *                | 40 |
     *              /         \
     * | 10 | 20 | 30 |     | 60 |
     * 
     * after rotation, the tree should look like
     *           | 30 |
     *         /        \ 
     * | 10 | 20 |    | 40 | 50 |
     * 
     */

    // TODO: do the right rotation here

    return true;
}

bool removeFromLeaf(int item, BTreeNode* parent, unsigned leaf_idx, unsigned order) {
    // sanity checks
    assert(!parent->is_leaf_);
    assert(leaf_idx < parent->children_.size());
    BTreeNode* leaf = parent->children_[leaf_idx];
    assert(leaf->is_leaf_);
    std::vector<int>& elems = leaf->elements_;
    std::vector<int>::iterator pos = std::find(elems.begin(), elems.end(), item);
    assert(pos != elems.end());

    std::cout << "removing " << item  << "..." << std::endl;

    // delete item, shift other items, shrink the size
    elems.erase(pos);

    std::cout << "Does the node underflow? ";

    // call rotateRight if current leaf node underflows
    if (underflows(elems.size(), order)) {
        std::cout << "Yes!" << std::endl;
        return parent->rotateRight(leaf_idx, order);
    }
    std::cout << "No!" << std::endl;
    return true;
}