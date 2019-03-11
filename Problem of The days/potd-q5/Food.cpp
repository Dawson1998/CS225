// Your code here
#include "Food.h"
#include <iostream>
using namespace std;

Food::Food()
{
  name_="";
  quantity_=0;
}

string Food::get_name()
{
  return name_;
}
void Food::set_name(string n)
{
  name_=n;
}
int Food::get_quantity()
{
  return quantity_;
}
void Food::set_quantity(int q)
{
  quantity_=q;
}
