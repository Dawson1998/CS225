#include <iostream>
#include "potd.h"

void printList(Node *head) {
  if (head == NULL) {
    std::cout << "Empty list" << std::endl << std::endl;
    return;
  }

  Node *temp = head;
  int count = 0;
  while(temp != NULL) {
    std::cout << "Node " << count << ": " << temp ->data_ << std::endl;
    count++;
    temp = temp->next_;
  }
  std::cout << std::endl;
}

int main() {
  // Empty List:
  Node *head = NULL;
  printList(head);

  // Add 3 to list:
  Node three;
  three.data_ = 3;
  three.next_ = NULL;
  insertSorted(&head, &three);
  printList(head);

  // Add 9 to list:
  Node nine;
  nine.data_ = 9;
  nine.next_ = NULL;
  insertSorted(&head, &nine);
  printList(head);

  // Add 1 to list:
  Node one;
  one.data_ = 1;
  one.next_ = NULL;
  insertSorted(&head, &one);
  printList(head);

  // Add 5 to list:
  Node five;
  five.data_ = 5;
  five.next_ = NULL;
  insertSorted(&head, &five);
  printList(head);

  return 0;
}
