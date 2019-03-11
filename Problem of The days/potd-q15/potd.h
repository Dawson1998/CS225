#pragma once

#include <string>

using namespace std;

struct Node {
    int data_;
    Node *next_;
};

string stringList(Node *n);