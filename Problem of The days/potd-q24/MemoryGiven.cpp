#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

unsigned maxAddress = 0x10000;

/**
Returns the next allocated memory chunk that occurs after the given node or NULL otherwise
*/
Node* Memory::findNextAllocatedMemoryChunk(Node* node) {
    Node* current = node->next;
    while (current != NULL) {
        if (current->inUse) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

/**
Returns the address of the allocated memory or -1 if allocation failed
*/
int Memory::allocate(size_t size) {
    Node* current = head;
    while (current != NULL) {

        if (!(current->inUse)) {
            // Check size of node
            size_t thisSize = getSize(current);

            if (thisSize >= size) {
                size_t remaining = thisSize - size;
                current->inUse = true;

                if (remaining > 0) {
                    // Create a new node
                    unsigned newAddress = current->address + size;
                    Node* next = current->next;
                    Node* newNext = new Node(newAddress, false);
                    if (next != NULL) {
                        newNext->next = next;
                        next->previous = newNext;
                    }

                    current->next = newNext;
                    newNext->previous = current;
                }
                return (int) current->address;
            }
        }

        current = current->next;
    }
    return -1;
}

Memory::Memory() {
    head = new Node(0, false);
}

/**
Returns the memory size of the given node
*/
size_t Memory::getSize(Node* node) {
    Node* next = node->next;
    size_t thisSize;
    unsigned thisAddress = node->address;
    if (next == NULL) {
        thisSize = maxAddress - thisAddress;
    } else {
        thisSize = next->address - thisAddress;
    }
    return thisSize;
}

unsigned Memory::usage() {
    size_t total = 0;
    Node* current = head;
    while (current != NULL) {
        if (!(current->inUse)) {
            total += getSize(current);
        }
        current = current->next;
    }
    return total;
}
unsigned Memory::available() {
    size_t total = 0;
    Node* current = head;
    while (current != NULL) {
        if (!current->inUse) {
            total += getSize(current);
        }
        current = current->next;
    }
    return total;
}

unsigned** Memory::getStats() {
    using namespace std;

    // Get length of linked list: n
    int n = 0;
    Node* current = head;
    while (current != NULL) {
        n += 1;
        current = current->next;
    }

    // Allocate 2d array of dimension n x 2
    unsigned** ret = new unsigned*[n];

    for (size_t i = 0; i < (size_t) n; i++) {
        ret[i] = new unsigned[2];
    }

    current = head;
    int index = 0;
    while (current != NULL) {
        unsigned address = current->address;
        bool inUse = current->inUse;

        ret[index][0] = address;
        ret[index][1] = inUse;

        index += 1;
        current = current->next;
    }

    return ret;
}

size_t Memory::numberOfChunks() {
    size_t count = 0;
    Node* current = head;
    while (current != NULL) {
        count += 1;

        current = current->next;
    }
    return count;
}

void Memory::printStats() {
    unsigned availableMemory = available();
    unsigned usedMemory = usage();

    std::cout << "==================================" << '\n';
    std::cout << "Available: 0x" << std::hex << availableMemory << " bits" << '\n';
    std::cout << "Used: 0x" << std::hex << usedMemory << " bits" << '\n';
    std::cout << "==================================" << '\n';

    Node* current = head;
    while (current != NULL) {
        unsigned addr = current->address;
        bool inUse = current->inUse;

        std::cout << "0x" << std::setfill('0') << std::setw(4) << std::hex << addr << ": " << (inUse ? "InUse" : "Free") << '\n';

        current = current->next;
    }

    std::cout << "" << '\n';
}
