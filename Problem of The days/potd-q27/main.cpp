#include <iostream>
#include <string>
#include "potd.h"

using namespace std;


int main(int argc, char** argv) {
  if (argc >= 2) {
    string s(argv[1]);

    cout << getFortune(s) << endl;

    return 0;
  } else {
    cout << "Usage: " << argv[0] << " <word>" << endl;
    return 1;
  }
}
