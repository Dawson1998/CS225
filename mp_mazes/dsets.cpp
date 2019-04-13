/* Your code here! */
#include "dsets.h"
#include <iostream>
using namespace std;

void DisjointSets::addelements(int num)
{
  for(int i=0;i<num;i++)
  {
    uptrees.push_back(-1);
  }
}

int DisjointSets::find(int elem)
{
  if(elem>=(int)uptrees.size())
  {
    return -1;
  }
  if(uptrees[elem]<0)
  {
    return elem;
  }
  //cout<<"here"<<endl;
  int root = find(uptrees[elem]);
  uptrees[elem] = root;
  return root;
}

void DisjointSets::print_set()
{
  // for(int i=0;i<(int)uptrees.size();i++){
  //   cout<<i<<"  ";
  // }
  //cout<<endl;
  for(int i=0;i<(int)uptrees.size();i++){
    cout<<uptrees[i]<<" ";
  }
  cout<<endl;
}

void DisjointSets::setunion(int first,int second)
{
  int temp1 = find(first);
  int temp2 = find(second);
  if(temp1==temp2)return;
  //cout<<temp1<<" "<<temp2<<endl;
  if(uptrees[temp1]>uptrees[temp2])//since size indeces are negative if temp1 size less point temp1 to temp2
  {
    uptrees[temp2]+=uptrees[temp1];//updating size
    uptrees[temp1] = temp2;//contents of temp1 points to temp2
    //cout<<"here"<<endl;
    //print_set();
    return;
  }
  uptrees[temp1]+=uptrees[temp2];//updating size
  uptrees[temp2] = temp1;//contents of temp2 points to temp1
  //cout<<"temp1>temp2"<<endl;
  //print_set();
}

int DisjointSets::size(int elem)
{
  int temp3 = find(elem);
  return -1*uptrees[temp3];
}
