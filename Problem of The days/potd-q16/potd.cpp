#include "potd.h"
#include <iostream>

void insertSorted(Node **head, Node *insert) {
  // your code here!
  if(*head==NULL)
  {
    *head=insert;
    return;
  }
  else
  {
    Node *temp = *head;
    if(insert->data_<temp->data_)
    {
      std::cout<<"pass 1\n";
      *head=insert;
      insert->next_=temp;
      return;
    }
    else
    {
      //std::cout<<"pass 1\n";
      while(temp->next_!=NULL)
      {
        if(insert->data_>temp->next_->data_)
        {
          temp=temp->next_;
          continue;
        }
        else
        {
          std::cout<<"pass 2\n";
          Node x=*temp;
          temp->next_=insert;
          insert->next_=x.next_;
          return;
        }
      }
    }

  }
  std::cout<<"pass 2\n";
  Node *x=*head;
  x->next_=insert;
  insert->next_=NULL;
  return;
}
