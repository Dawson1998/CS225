// Your code here
#include "potd.h"
#include <string>
#include <iostream>

string getFortune(const string &s)
{
  int x = s.length()%5;
  switch(x)
  {
    case 0:
      return "Hi whats your name?";
    case 1:
      return "string getFortune(const string &s)";
    case 2:
      return "int x = s.length()%5;";
    case 3:
      return "return \"int x = s.length()%5;";
    case 4:
      return "return \"return \"int x = s.length()%5;\";";
    default:
      return "";

  }
}
