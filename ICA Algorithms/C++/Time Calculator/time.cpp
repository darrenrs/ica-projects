#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

Interval new_interval(int D, int h, int m, int s, int ms) {
  Interval interval;

  interval.days = D;
  interval.hours = h;
  interval.minutes = m;
  interval.seconds = s;
  interval.milliseconds = ms;

  return interval;
}

Interval new_interval(int ms) {
  Interval interval;

  interval.days = ms / 86400000;
  ms %= 86400000;

  interval.hours = ms / 3600000;
  ms %= 3600000;

  interval.minutes = ms / 60000;
  ms %= 60000;

  interval.seconds = ms / 1000;
  ms %= 1000;

  interval.milliseconds = ms;

  return interval;
}

Interval add_interval(Interval dt1, Interval dt2) {
  int ms1 = dt1.days * 86400000 +
    dt1.hours * 3600000 +
    dt1.minutes * 60000 +
    dt1.seconds * 1000 +
    dt1.milliseconds;

  int ms2 = dt2.days * 86400000 +
    dt2.hours * 3600000 +
    dt2.minutes * 60000 +
    dt2.seconds * 1000 +
    dt2.milliseconds;

  return new_interval(ms1 + ms2);
}

void interval_print(Interval dt) {
  cout.fill(' ');
  cout << setw(4) << dt.days;
  cout.fill('0');
  cout << "d, " << setw(2) << dt.hours << ":" << setw(2) << dt.minutes << ":" << setw(2) << dt.seconds << "." << setw(3) << dt.milliseconds << endl;
  cout.fill(' ');
}