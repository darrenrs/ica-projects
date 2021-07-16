#pragma once

struct Interval {
  int days;
  int hours;
  int minutes;
  int seconds;
  int milliseconds;
};

Interval new_interval(int D, int h, int m, int s, int ms);
Interval new_interval(int ms);
Interval add_interval(Interval dt1, Interval dt2);
void interval_print(Interval dt);