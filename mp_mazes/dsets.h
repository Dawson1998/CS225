/* Your code here! */
#pragma once
#include <vector>
using namespace std;

class DisjointSets
{
  public:
    vector<int> uptrees;
    void addelements(int);
    int find(int);
    void setunion(int,int);
    int size(int);
    void print_set();
};
