#include <iostream>
#include "time.h"

using namespace std;

int main() {
  Interval i1 = new_interval(1, 12, 25, 40, 867);
  interval_print(i1);

  Interval i2 = new_interval(1928487124);
  interval_print(i2);

  Interval i3 = add_interval(i1, i2);
  interval_print(i3);

  return 0;
}