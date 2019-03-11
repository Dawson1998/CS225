#include <iostream>
#include "TreeNode.h"
using namespace std;

int main() {
  TreeNode n1, n2, n3, n4;

  n1.left_ = &n2;
  n1.right_ = &n3;
  n2.left_ = &n4;

  cout << "Height of n1: " << n1.getHeight() << endl;
  cout << "Height of n2: " << n2.getHeight() << endl;
  cout << "Height of n3: " << n3.getHeight() << endl;
  cout << "Height of n4: " << n4.getHeight() << endl;

  return 0;
}
