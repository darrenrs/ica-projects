#pragma once

class SortManager {
  public:
    SortManager(const unsigned int capacity);
    void populate();
    void full();
    virtual void sort() = 0;
    void print();
  
  protected:
    std::vector<int> vector;
    unsigned int capacity;
    std::string name;
};