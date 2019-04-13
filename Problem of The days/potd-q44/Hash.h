#ifndef _HASH_H
#define _HASH_H

#include <string>
#include <vector>

class HashTable
{
    private:
        std::vector<std::string>* table;             // The hash table
        int M;
        unsigned long bernstein(std::string str, int M);

    public:
        HashTable(int M);
        void printKeys();
        void insert(std::string str);
        bool contains(std::string str);
};

#endif
