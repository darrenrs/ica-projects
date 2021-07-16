#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "sortalg.h"

int main() {
  int globalCapacity;

  std::cout << "How many list entries? ";
  std::cin >> globalCapacity;
  std::cout << std::endl;
  
  if (globalCapacity <= 10000) {
    BubbleSort bubbleSort = BubbleSort(globalCapacity);
    bubbleSort.full();
    
    SelectionSort selectionSort = SelectionSort(globalCapacity);
    selectionSort.full();
  } else {
    std::cout << "Bubble Sort and Selection Sort are garbage, so we'll skip them." << std::endl << std::endl;
  }
  
  RadixSort radixSort = RadixSort(globalCapacity);
  radixSort.full();
  
  STLSort stlSort = STLSort(globalCapacity);
  stlSort.full();

  STLStableSort stlStableSort = STLStableSort(globalCapacity);
  stlStableSort.full();

  return 0;
}