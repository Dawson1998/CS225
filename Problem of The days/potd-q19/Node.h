#pragma once

#include <string>

class Node {
    public:
        int data_;
        Node *next_;
        Node();
        Node(const Node &other);
        ~Node();
        static int getNumNodes() {
            return numNodes;
        }
    private:
        static int numNodes;
};

Node *listUnion(Node *first, Node *second);
