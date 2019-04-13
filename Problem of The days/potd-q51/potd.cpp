#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


vector<string> topThree(string filename) {
    string line;
    ifstream infile (filename);
    vector<string> ret;
    vector<int> valcount;
    vector<int> key;
    if (infile.is_open()) {
        while (getline(infile, line)) {
          std::cout<<line;
          break;
        }
    }
    infile.close();
    return ret;
}
