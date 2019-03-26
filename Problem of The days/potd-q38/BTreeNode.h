#pragma once

#include <string>
#include <vector>

struct BTreeNode {
    bool is_leaf_ = true;
    std::vector<int> elements_;
    std::vector<BTreeNode*> children_;
    BTreeNode() {}
    BTreeNode(std::vector<int> v) {
      this->elements_ = v;
    }
    /**
     * Fix the underflow child node at idx by rotating right
     * (borrowing a node from left sibling).
     * @param idx The underflow child to be fixed is at children_[idx].
     * @return If the rotation can be done.
     */
    bool rotateRight(unsigned idx, unsigned order);
};

/**
 * Check if the given number of elements in a BTree node underflows.
 * @param numElem Number of elements in this node.
 * @param order The order of the BTree.
 * @return True if it underflows, False otherwise.
 */
bool underflows(unsigned numElem, unsigned order);


/**
 * A special case for removing an element from BTree. Assume elem exists in leaf.
 * @param item The element to be removed.
 * @param parent The parent node that contains the leaf node as a child.
 * @param leaf_idx The leaf BTreeNode idx that contains the element to be removed.
 * @return If the removal is successful.
 */
bool removeFromLeaf(int item, BTreeNode* parent, unsigned leaf_idx, unsigned order);
