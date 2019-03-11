#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
    if (head==NULL)
    {
      return "Empty list";
    }
    else
    {
      Node *temp = head;
      string asd ="";
      int a=0;
      while(temp!=NULL)
      {
        if(a>0)
        {
          asd=asd+" -> ";
        }
        asd=asd+"Node "+std::to_string(a)+": "+std::to_string(temp->data_);
        a++;
        temp=temp->next_;
      }
      return asd;
    }
}
