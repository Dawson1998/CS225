#include "Node.h"
#include <cstdlib>

Node::Node(unsigned addr, bool inUse) {
    this->address = addr;
    this->inUse = inUse;
    next = NULL;
    previous = NULL;
}
