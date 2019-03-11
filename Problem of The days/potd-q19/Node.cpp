#include "Node.h"
#include <iostream>
/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data) {
    //std::cout<<"pass3"<<std::endl;
    // your code here
    Node * t = first;
    Node * tt = first;
    if(first==NULL)
    {
      Node *temp = new Node();
      temp->data_=data;
      temp->next_=NULL;
      first=temp;
      return first;
    }
    while(tt!=NULL)
    {
      if(tt->data_==data)
      {
        return first;
      }
      tt=tt->next_;
    }
    if(first->data_>data)
    {
      Node *temp = new Node();
      temp->data_=data;
      temp->next_=NULL;
      first = temp;
      first->next_ = t;
      //temp->next_=NULL:
      //delete temp;
      return first;
    }
    if(data == first->data_)
    {
      return first;
    }
    //std::cout<<"pass4"<<std::endl;
    while(t->next_!=NULL&&data>t->next_->data_)
    {
      if(data==t->data_)
      {
        return first;
      }
      t=t->next_;
    }
    //std::cout<<"pass5"<<std::endl;
    Node *temp = new Node();
    temp->data_=data;
    temp->next_=NULL;
    temp->next_=t->next_;
    t->next_=temp;
    return first;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node *out = NULL;
    //Node::numNodes--;
    while (first != NULL) {
        //std::cout<<"pass1"<<std::endl;
        // your code here
        // hint: call insertSorted and update l1
        out=insertSorted(out,first->data_);
        first=first->next_;
    }
    while (second != NULL) {
        // your code here
        //std::cout<<"pass2"<<std::endl;
        out=insertSorted(out,second->data_);
        second=second->next_;
    }

    return out;
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
