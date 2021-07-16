#pragma once
#include "sortmgr.h"

class BubbleSort : public SortManager {
  public:
    BubbleSort(const unsigned int capacity) : SortManager(capacity) {
      this->name = "Bubble Sort       ";
    };
    void sort();
};

class SelectionSort : public SortManager {
  public:
    SelectionSort(const unsigned int capacity) : SortManager(capacity) {
      this->name = "Selection Sort    ";
    };
    void sort();
};

class RadixSort : public SortManager {
  public:
    RadixSort(const unsigned int capacity) : SortManager(capacity) {
      this->name = "Radix Sort        ";
    };
    void sort();
  
  private:
    double radixSortMaxLog(std::vector<int> list);
};

class STLSort : public SortManager {
  public:
    STLSort(const unsigned int capacity) : SortManager(capacity) {
      this->name = "STL Sort          ";
    };
    void sort();
};

class STLStableSort : public SortManager {
  public:
    STLStableSort(const unsigned int capacity) : SortManager(capacity) {
      this->name = "STL Sort (stable) ";
    };
    void sort();
};