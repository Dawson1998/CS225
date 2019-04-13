#include <algorithm>
#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "level.h"

using namespace std;

int main()
{
    // Creating a heap
    vector<int> elems = {1,2,3};
    MinHeap myHeap(elems);

    // Printing a heap
    cout << "myHeap: " << endl;
    myHeap.print();

    // Testing your answer
    vector<int> leafNodes = lastLevel(myHeap);
    cout << "The leaf nodes are" << endl;
    for (size_t i = 0; i < leafNodes.size(); i ++)
        cout << leafNodes[i] << ' ';
    cout << endl;

    // Checking correctness
    vector<int> expected = {2,3};
    if (expected == leafNodes)
        cout << "Your output is correct" << endl;
    else
        cout << "Your output is incorrect" << endl;

    return 0;
}
