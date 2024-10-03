#include "vector"
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

void print(std::vector<int> src) {
  for (auto num : src)
    std::cout << num << "\n";
  std::cout << "\n";
}

void insert_element_max_heap(int data, std::vector<int> &src) {

  src.push_back(data);
  int pos = src.size() - 1; // posicion inicial

  while (src[pos] > src[(pos - 1) / 2] && pos > 0) {
    std::swap(src[pos], src[(pos - 1) / 2]);
    pos = (pos - 1) / 2;
  }
}
void insert_element_min_heap(int data, std::vector<int> &src) {

  src.push_back(data);
  int pos = src.size() - 1; // posicion inicial

  while (src[pos] < src[(pos - 1) / 2] && pos > 0) {
    std::swap(src[pos], src[(pos - 1) / 2]);
    pos = (pos - 1) / 2;
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> heap_mem = {30, 20, 15, 5, 10, 12, 6};
  std::vector<int> heap_mem_2 = {40, 30, 25, 15, 20, 22, 16};
  std::cout << "Primer heap original: \n";
  print(heap_mem);
  insert_element_max_heap(25, heap_mem);
  std::cout << "Primer Heap después de insertar 25 max heap: \n";
  print(heap_mem);

  insert_element_max_heap(35, heap_mem);
  std::cout << "Primer Heap después de insertar 35 max heap: \n";
  print(heap_mem);

  std::cout << "Segundo heap original: \n";
  print(heap_mem_2);

  std::cout << "Segundo heap después de insertar 50 con min heap" << "\n";
  insert_element_min_heap(50, heap_mem_2);
  print(heap_mem_2);
  std::cout << "Segundo heap después de insertar 3 con min heap" << "\n";
  insert_element_min_heap(3, heap_mem_2);
  print(heap_mem_2);
  return 0;
}
