#pragma once
#include <string>
#include <iostream>

using namespace std;

class Container {
  public:
    int get_alloc();
    string get_alloc_string();
    int get_capacity();
    string get_capacity_string();
    int set_alloc(int delta);
    Container(int max_capacity, int current_alloc);
    ~Container();

  private:
    int max_capacity;
    int current_alloc;
    string unit = "ml.";
};

Container::Container(int max_capacity, int current_alloc) {
  this->max_capacity = max_capacity;
  this->current_alloc = current_alloc;
}

int Container::get_alloc() {
  return this->current_alloc;
}

string Container::get_alloc_string() {
  return to_string(this->current_alloc) + " " + this->unit;
}

int Container::get_capacity() {
  return this->max_capacity;
}

string Container::get_capacity_string() {
  return to_string(this->max_capacity) + " " + this->unit;
}

int Container::set_alloc(int delta) {
  if ((this->current_alloc + delta) > this->max_capacity) {
    int old_alloc = this->current_alloc;
    this->current_alloc = this->max_capacity;
    
    return delta - (this->current_alloc - old_alloc);
  } else if ((this->current_alloc + delta) < 0) {
    cout << "Can't add to a full container." << endl << endl;
    return 0;
  } else {
    this->current_alloc += delta;
    return 0;
  }
}

Container::~Container() {

}