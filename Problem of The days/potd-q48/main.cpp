#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "NoProblem.cpp"

int main() {

    int start = 5;
    vector<int> created = {3, 0, 3, 5, 8, 2, 1, 0, 3, 5, 6, 9};
    vector<int> needed  = {0, 0, 10, 2, 6, 4, 1, 0, 1, 1, 2, 2};

    vector<string> result = NoProblem(start, created, needed);

    for(vector<string>::iterator it = result.begin();
            it != result.end();
            it ++)
        cout << *it << endl;
}
