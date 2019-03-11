#pragma once

#include "Node.h"
#include <cstdlib>
#include <vector>
#include <utility>

extern unsigned maxAddress;

class Memory {
public:

    Memory();

    int allocate(size_t size);
    bool free(unsigned address);

    void defragment();

    unsigned usage();
    unsigned available();

    void printStats();

    unsigned** getStats();
    size_t numberOfChunks();
private:
    size_t getSize(Node* node);
    Node* findNextAllocatedMemoryChunk(Node* node);
    Node* head;

};
