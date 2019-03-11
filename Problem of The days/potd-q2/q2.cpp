/* Problem of the Day #2 */

#include <ctime>
#include <iostream>
#include "epoch.h"

using namespace std;

int main() {
  time_t sec_since_epoch = time(nullptr);

  cout << "Hours: " << hours(sec_since_epoch) << endl;
  cout << "Days: " << days(sec_since_epoch) << endl;
  cout << "Years: " << years(sec_since_epoch) << endl;

  return 0;
}
