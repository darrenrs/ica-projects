#pragma once

#include <iostream>
#include <string>

using namespace std;

class Address {
  public:
    Address(string s, string c) : street(s), city(c) {
    }

    void display() {
      cout << street << ", " << city << endl;
    }

  private:
    string street;
    string city;
};