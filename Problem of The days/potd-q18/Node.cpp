#include "Node.h"
#include <iostream>
void mergeList(Node *first, Node *second) {
  //std::cout<<"pass"<<std::endl;
  // your code here!
  /*while(temp1!=NULL)
  {
    std::cout<<temp1->data_;
    if(temp1==NULL)
    {
      first = second;
    }
    if(temp2==NULL)
    {
      return;
    }
    first->next_=second;
    if(temp1->next_!=NULL)
    {
        second->next_=temp1->next_;
        first=temp1->next_;
    }
    else
    {
      return;
    }
    if(temp2->next_!=NULL)
    {
        second=temp2->next_;
    }
    else
    {
      return;
    }
  }*/
  if(first==NULL)
  {
    first = second;
    return;
  }
  if(second==NULL)
  {
    return;
  }
  Node temp1 = *first;
  Node temp2 = *second;
  first->next_=second;
  if(temp1.next_!=NULL)
  {
      second->next_=temp1.next_;
  }
  first = temp1.next_;
  second=temp2.next_;
  mergeList(first,second);
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
