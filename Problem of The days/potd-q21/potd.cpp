#include "potd.h"
#include <iostream>
#include <vector>
using namespace std;
double sum(vector<double>::iterator start, vector<double>::iterator end)
{
  double s = 0;
  while(start!=end)
  {
    s = s+*start;
    start++;
  }
  return s;
}

/** Returns an iterator that points to the element with the largest value between start and end. */
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end)
{
  vector<double>::iterator temp;
  vector<double>::iterator temp2 = start;
  double largest = *temp2;
  while(temp2!=end)
  {
    if(*temp2>=largest)
    {
      largest = *temp2;
      temp = temp2;
    }
    temp2++;
  }
  return temp;
}

/** Sort, in descending order, part of an array between start to end.
	Hint: use max_iter.
*/
void sort_vector(vector<double>::iterator start, vector<double>::iterator end)
{
  //vector<double>::iterator stemp = start;
  /*if(start==end)
  {
    return;
  }*/
  //vector<double>::iterator start2 = start;
  vector<double>::iterator temp2 = start;
  while(temp2!=end)
  {
    double temp = *temp2;
    std::cout <<*temp2<<std::endl;
    std::vector<double>::iterator max=max_iter(temp2,end);
    std::cout <<"here1 "<<*max<<std::endl;
    *temp2= *max;
    std::cout <<"here2"<<std::endl;
    *max = temp;
    std::cout <<"here"<<std::endl;
    temp2++;
  }
}
// Your code here!
