#include "epoch.h"
/* Your code here! */
int hours(time_t t)
{
  int x=t/60/60;
  return x;
}

int days(time_t t)
{
  int x=hours(t);
  int y=x/24;
  return y;
}

int years(time_t t)
{
  int x = days(t);
  int y = x/365;
  return y;
}
