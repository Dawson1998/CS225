#include "Node.h"
#include <iostream>
using namespace std;
Node *listIntersection(Node *first, Node *second) {
  // your code here
  Node * tempf = first;

  Node * out = NULL;
  int outc = 0;

  while(tempf!=NULL)
  {
    Node *temps = second;
    while(temps!=NULL)
    {
      if (temps->data_==tempf->data_)
      {
        if(outc == 0)
        {
          out = new Node();
          out->next_ = NULL;
          out->data_=tempf->data_;
          temps = temps->next_;
          outc++;
          continue;
        }
        Node *temp = out;
        bool issame = false;
        while(temp !=NULL)
        {
          if(tempf->data_==temp->data_)
          {
            issame = true;
            break;
          }
          temp  =temp->next_;
        }
        if(issame!=true)
        {
          Node * temp1 = new Node();
          temp1->next_ = out;
          temp1->data_ = tempf->data_;
          out = temp1;
        }
      }
      temps = temps->next_;
    }
    tempf = tempf->next_;
  }
  return out;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
