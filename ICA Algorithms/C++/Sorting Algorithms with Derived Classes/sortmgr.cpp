#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>

#include "sortmgr.h"

SortManager::SortManager(const unsigned int capacity) {
  this->capacity = capacity;
  this->populate();
}

void SortManager::populate() {
  int sum = 1;

  for (unsigned int i = 0; i < this->capacity; i++) {
    this->vector.push_back(sum);

    sum += 2 * (i + 7);

    sum %= (i + 1);
  }
}

void SortManager::full() {
  std::cout << "========== " << this->name << " ==========\r\n";
  
  if (this->capacity <= 100) {
    std::cout << "=== BEFORE ===\r\n";
    this->print();
  }

  auto timeStart = std::chrono::high_resolution_clock::now();
  this->sort();
  auto timeEnd = std::chrono::high_resolution_clock::now();
  auto timeElapsed = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart).count();

  if (this->capacity <= 100) {
    std::cout << "\r\n=== AFTER ===\r\n";
    this->print();
  }
  
  std::cout << "The operation took " << timeElapsed << " µs." << std::endl;

  for (int i = 0; i < this->name.length() + 22; i++) {
    std::cout << "=";
  }

  std::cout << std::endl << std::endl;
}

void SortManager::print() {
  for (int i : this->vector) {
    std::cout << i << ", ";
  }
  std::cout << "\b\b";
  std::cout << " (length " << vector.size() << ")";
  std::cout << std::endl;
}