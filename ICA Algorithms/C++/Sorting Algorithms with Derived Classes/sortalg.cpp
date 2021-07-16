#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "sortalg.h"

void BubbleSort::sort() {
  std::vector<int> list = this->vector;
  int length = list.size();
  
  for (int i = 0; i < (length - 1); i++) {
    for (int j = 0; j < (length - i - 1); j++) {
      if (list[j] > list[j + 1]) {
        std::swap(list[j], list[j + 1]);
      }
    }
  }

  this->vector = list;
}

void SelectionSort::sort() {
  std::vector<int> list = this->vector;
  int length = list.size();
  
  for (int i = 0; i < length - 1; i++) {
    int min = i;
    for (int j = i + 1; j < length; j++) {
      if (list[j] < list[min]) {
        min = j;
      }
    }
    std::swap(list[min], list[i]);
  }
  
  this->vector = list;
}

double RadixSort::radixSortMaxLog(std::vector<int> list) {
  int max = list[0];
  for (int i : list) {
    if (i > max) {
      max = i;
    }
  }

  return floor(log10(max));
}

void RadixSort::sort() {
  std::vector<int> list = this->vector;
  int length = list.size();
  double maxLog = this->radixSortMaxLog(list);

  std::vector<std::vector<int>> rootHolder(10);

  for (int i = 0; i < maxLog + 1; i++) {
    for (int j = 0; j < length; j++) {
      double modulusSignificance = floor((double)(list[j] % (int)pow(10, i + 1)) / pow(10, i));
      
      rootHolder[modulusSignificance].push_back(list[j]);
    }

    list.clear();

    for (int x = 0; x < rootHolder.size(); x++) {
      for (int y = 0; y < rootHolder[x].size(); y++) {
        list.push_back(rootHolder[x][y]);
      }
      rootHolder[x].clear();
    }
  }

  this->vector = list;
}

void STLSort::sort() {
  std::vector<int> list = this->vector;
  std::sort(list.begin(), list.end());
  this->vector = list;
}

void STLStableSort::sort() {
  std::vector<int> list = this->vector;
  std::stable_sort(list.begin(), list.end());
  this->vector = list;
}