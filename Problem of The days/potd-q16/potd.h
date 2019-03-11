#pragma once

#include <string>

struct Node {
    int data_;
    Node *next_;
};

void insertSorted(Node **head, Node *item);
