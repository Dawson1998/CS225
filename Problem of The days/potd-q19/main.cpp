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
  Node n_0, n_1, n_2, n_22, n_3, n_4;
  n_0.data_ = 0;
  n_1.data_ = 1;
  n_2.data_ = 2;
  n_22.data_ = 2;
  n_3.data_ = 3;
  n_4.data_ = 4;

  n_0.next_ = &n_1;
  n_1.next_ = &n_2;
  n_2.next_ = NULL;

  n_22.next_ = &n_3;
  n_3.next_ = &n_4;
  n_4.next_ = NULL;

  std::cout<<"First List:"<<std::endl;
  printList(&n_0);
  std::cout<<"Second List:"<<std::endl;
  printList(&n_22);

  Node *union1 = listUnion(&n_0, &n_22);
  std::cout<<"Union:"<<std::endl;
  printList(union1);
  std::cout<<std::endl;


  // Example #2
  Node p00, p01, p02, p03, p10, p11, p12, p13;

  // List 1: 0 2 2 2
  p00.data_ = 0; p00.next_ = &p01;
  p01.data_ = 2; p01.next_ = &p02;
  p02.data_ = 2; p02.next_ = &p03;
  p03.data_ = 2; p03.next_ = NULL;

  // List 2: 0 0 0 4
  p10.data_ = 0; p10.next_ = &p11;
  p11.data_ = 0; p11.next_ = &p12;
  p12.data_ = 0; p12.next_ = &p13;
  p13.data_ = 4; p13.next_ = NULL;

  std::cout<<"First List:"<<std::endl;
  printList(&p00);
  std::cout<<"Second List:"<<std::endl;
  printList(&p10);

  Node *union2 = listUnion(&p00, &p10);
  std::cout<<"Union:"<<std::endl;
  printList(union2);
  std::cout<<std::endl;

  return 0;
}
