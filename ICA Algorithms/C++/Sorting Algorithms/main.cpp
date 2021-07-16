#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>

auto timeElapsed(std::chrono::high_resolution_clock::time_point start,
                 std::chrono::high_resolution_clock::time_point end) {
  return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

template <typename T>
void printVector(std::vector<T> vector) {
  for (int i : vector) {
    std::cout << i << ", ";
  }
  std::cout << "length " << vector.size();
  std::cout << std::endl;
}

template <typename T>
std::vector<T> bubbleSort(std::vector<T> list) {
  int length = list.size();
  
  for (int i = 0; i < (length - 1); i++) {
    for (int j = 0; j < (length - i - 1); j++) {
      if (list[j] > list[j + 1]) {
        std::swap(list[j], list[j + 1]);
      }
    }
  }

  return list;
}

template <typename T>
std::vector<T> selectionSort(std::vector<T> list) {
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
  
  return list;
}

template <typename T>
double radixSortMaxLog(std::vector<T> list) {
  T max = list[0];
  for (int i : list) {
    if (i > max) {
      max = i;
    }
  }

  return floor(log10(max));
}

template <typename T>
std::vector<T> radixSort(std::vector<T> list) {
  int length = list.size();
  double maxLog = radixSortMaxLog(list);

  std::vector<std::vector<T>> rootHolder(10);

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

  return list;
}

template <typename T>
std::vector<T> STLSort(std::vector<T> list) {
  std::sort(list.begin(), list.end());
  return list;
}

template <typename T>
std::vector<T> STLStableSort(std::vector<T> list) {
  std::stable_sort(list.begin(), list.end());
  return list;
}

int main() {
  std::vector<int> baseList;
  unsigned int sum = 0;
  unsigned int mainLength = 19;

  for (unsigned int i = 0; i < mainLength; i++) {
    baseList.push_back(sum);

    sum += 2 * (i + 7);

    sum %= (i + 1);
  }

  /* PRINT ORIGINAL LIST */

  std::cout << "Original List: ";
  printVector(baseList);
  std::cout << std::endl;

  /* BUBBLE SORT */
  
  auto timeStartBubbleSort = std::chrono::high_resolution_clock::now();
  std::vector<int> listBubbleSort = bubbleSort(baseList);
  auto timeEndBubbleSort = std::chrono::high_resolution_clock::now();
  
  std::cout << "Bubble Sort: ";
  printVector(listBubbleSort);
  std::cout << "The sort took " << (timeElapsed(timeStartBubbleSort, timeEndBubbleSort)) << " µs." << std::endl;
  std::cout << std::endl;

  /* SELECTION SORT */
  
  auto timeStartSelectionSort = std::chrono::high_resolution_clock::now();
  std::vector<int> listSelectionSort = selectionSort(baseList);
  auto timeEndSelectionSort = std::chrono::high_resolution_clock::now();
  
  std::cout << "Selection Sort: ";
  printVector(listSelectionSort);
  std::cout << "The sort took " << (timeElapsed(timeStartSelectionSort, timeEndSelectionSort)) << " µs." << std::endl;
  std::cout << std::endl;

  /* RADIX SORT */
  
  auto timeStartRadixSort = std::chrono::high_resolution_clock::now();
  std::vector<int> listRadixSort = radixSort(baseList);
  auto timeEndRadixSort = std::chrono::high_resolution_clock::now();
  
  std::cout << "Radix Sort: ";
  printVector(listRadixSort);
  std::cout << "The sort took " << (timeElapsed(timeStartRadixSort, timeEndRadixSort)) << " µs." << std::endl;
  std::cout << std::endl;

  /* std::sort (STL QuickSort) */
  
  auto timeStartSTLSort = std::chrono::high_resolution_clock::now();
  std::vector<int> listSTLSort = STLSort(baseList);
  auto timeEndSTLSort = std::chrono::high_resolution_clock::now();
  
  std::cout << "std::sort (STL QuickSort): ";
  printVector(listSTLSort);
  std::cout << "The sort took " << (timeElapsed(timeStartSTLSort, timeEndSTLSort)) << " µs." << std::endl;
  std::cout << std::endl;

  /* std::stable_sort (STL Merge Sort) */
  
  auto timeStartSTLStableSort = std::chrono::high_resolution_clock::now();
  std::vector<int> listSTLStableSort = STLStableSort(baseList);
  auto timeEndSTLStableSort = std::chrono::high_resolution_clock::now();
  
  std::cout << "std::stable_sort (STL Merge Sort): ";
  printVector(listSTLStableSort);
  std::cout << "The sort took " << (timeElapsed(timeStartSTLStableSort, timeEndSTLStableSort)) << " µs." << std::endl;


}