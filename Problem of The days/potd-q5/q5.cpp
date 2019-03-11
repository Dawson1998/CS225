#include "Food.h"
#include <iostream>
void increase_quantity(Food * x)
{
  x->Food::set_quantity(x->get_quantity()+1);
}
