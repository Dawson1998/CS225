#include "Derived.h"
#include "Base.h"

using namespace std;
string Derived::foo()
{
  return "I will not eat them.";
}
string Derived::bar()
{
  return "And Ham";
}
Derived::~Derived()
{
  return;
}
