#pragma once

#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class Star : public Actor {
  public:
    Star(string n, string a, double b, string s, string c) : Actor(n, a, s, c), balance(b) {
    }

    void display() {
      Actor::display();
      cout << balance << endl;
    }
  
  private:
    double balance;
};