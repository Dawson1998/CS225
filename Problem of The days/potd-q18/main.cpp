#include <iostream>
#include "Node.h"

void printList(Node *head) {
  if (head == NULL) {
    std::cout << "Empty list" << std::endl;
    return;
  }

  Node *temp = head;
  int count = 0;
  while(temp != NULL) {
    std::cout << "Node " << std::to_string(count) << ": " << temp ->data_ << std::endl;
    count++;
    temp = temp->next_;
  }
}

int main() {
  // Example #1
  Node n0, n2, n4, n11, n33, n55;
  n0.data_ = 0;
  n2.data_ = 2;
  n4.data_ = 4;
  n11.data_ = 11;
  n33.data_ = 33;
  n55.data_ = 55;

  n0.next_ = &n2;
  n2.next_ = &n4;
  n4.next_ = NULL;

  n11.next_ = &n33;
  n33.next_ = &n55;
  n55.next_ = NULL;

  std::cout<<"First List:"<<std::endl;
  printList(&n0);
  std::cout<<"Second List:"<<std::endl;
  printList(&n11);

  mergeList(&n0, &n11);

  std::cout<<"Merged List:"<<std::endl;
  printList(&n0);
  std::cout<<std::endl;

  // Example #2
  Node p0, p2, p11, p33, p33_2, p44;
  p0.data_ = 0;
  p2.data_ = 2;
  p11.data_ = 11;
  p33.data_ = 33;
  p33_2.data_ = 33;
  p44.data_ = 44;

  p0.next_ = &p2;
  p2.next_ = NULL;

  p11.next_ = &p33;
  p33.next_ = &p33_2;
  p33_2.next_ = &p44;
  p44.next_ = NULL;

  std::cout<<"First List:"<<std::endl;
  printList(&p0);
  std::cout<<"Second List:"<<std::endl;
  printList(&p11);

  mergeList(&p0, &p11);

  std::cout<<"Merged List:"<<std::endl;
  printList(&p0);

  return 0;
}
