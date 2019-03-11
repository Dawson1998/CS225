#include "Node.h"
#include <iostream>
void sortList(Node **head) {
  // your code here!

  /*
  Selection sort:
  Repeatedly moving the minimum node
  to the beginning
  */


  // Some variables you probably will
  Node *minNode = NULL;
  Node *minPrev = NULL;

  if (*head == NULL)
      return;

  int minData = (*head)->data_;
  Node *tmp = *head;
  //Node *min = NULL;
  Node *prev = NULL;

  while ( tmp != NULL ) {
      //std::cout<<"pass1\n"<<std::endl;
      // TODO: Find the minimum node
      if (tmp->data_<minData)
      {
        minData=tmp->data_;
        minNode=tmp;
        minPrev=prev;
      }
      prev=tmp;
      tmp=tmp->next_;
  }

  if (minPrev!=NULL && minNode != NULL) {
      // TODO: Move the minimum node to the beginning
      // and update head
      //std::cout<<minNode->data_<<"\n"<<std::endl;
      //std::cout<<"pass2\n"<<std::endl;
      //Node *temp=(*head);
      minPrev->next_=minNode->next_;
      minNode->next_=*head;
      *head=minNode;
  }

  // Recurse on the rest of the list
  sortList(& (*head)->next_);
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
