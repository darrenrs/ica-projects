#pragma once

#include "Address.h"
#include "Date.h"

class Person {
  public:
    Person(Person &p) : name(p.name) {
      address = new Address(*p.address);
      date = new Date(*p.date);
    }

    Person(string n, string s, string c) : name(n), address(nullptr), date(nullptr) {
      setAddress(s, c);
    }

    ~Person() {
      if (date != nullptr) {
        delete date;
      }

      if (address != nullptr) {
        delete address;
      }
    }

    void setAddress(string c, string s) {
      if (address != nullptr) {
        delete address;
      }
      address = new Address(c, s);
    }

    void setDate(int y, int m, int d) {
      if (date != nullptr) {
        delete date;
      }
      date = new Date(y, m, d);
    }

    void display() {
      cout << name << endl;
      if (address != nullptr) {
        address->display();
      }
      if (date != nullptr) {
        date->display();
      }
    }
  
  private:
    string name;
    string street;
    string city;
    Address* address = nullptr;
    Date* date = nullptr;
};