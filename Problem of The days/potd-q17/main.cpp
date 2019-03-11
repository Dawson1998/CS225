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
    std::cout << "Node " << count << ": " << temp ->data_ << std::endl;
    count++;
    temp = temp->next_;
  }
}

int main() {
  // Create an unsorted list:
  Node one, two, three, four, five;
  one.data_ = 1;
  two.data_ = 2;
  three.data_ = 3;
  four.data_ = 4;
  five.data_ = 5;

  // 2 -> 4 -> 1 -> 5 -> 3
  Node *head = &two;
  two.next_ = &four;
  four.next_ = &one;
  one.next_ = &five;
  five.next_ = &three;
  three.next_ = NULL;

  // Unsorted List:
  std::cout<<"Unsorted List:"<<std::endl;
  printList(head);
  std::cout << "# of Nodes before sortList: " << Node::getNumNodes() <<std::endl;

  // Sorted List:
  sortList(&head);
  std::cout<<"Sorted List:"<<std::endl;
  printList(head);

  std::cout << "# of Nodes after sortList: " << Node::getNumNodes() << std::endl;
  return 0;
}
