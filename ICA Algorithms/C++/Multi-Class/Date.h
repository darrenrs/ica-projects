#pragma once

#include <iostream>

using namespace std;

class Date {
  public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {
    }

    void display() {
      cout << year << "-" << month << "-" << day << endl;
    }
  
  private:
    int year;
    int month;
    int day;
};