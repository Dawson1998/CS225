#pragma once

class Node {
public:
    Node(unsigned addr, bool inUse);
    unsigned address;
    bool inUse;
    Node* next;
    Node* previous;
};
