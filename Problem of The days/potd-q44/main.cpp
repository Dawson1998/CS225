#include <string>
#include <iostream>
#include<algorithm>
#include <vector>
#include "Hash.h"

int main()
{
	HashTable h(10);
	h.insert("aaa");
	h.insert("aaa");
	h.insert("ccc");
    std::cout<<"Does the hash table contain bbb? "<<h.contains("bbb")<<"\n";
	std::cout<<"Does the hash table contain aaa? "<<h.contains("aaa")<<"\n";
	std::cout<<"Contents of the hash table:\n";	
	h.printKeys();
}
