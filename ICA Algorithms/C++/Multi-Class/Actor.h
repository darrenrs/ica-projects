#pragma once

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Actor : public Person {
  public:
    Actor(string n, string a, string s, string c) : Person(n, s, c), agent(a) {
    }

    void display() {
      Person::display();
      cout << agent << endl;
    }
  
  private:
    string agent;
};