#include <iostream>
#include <vector>
void remove_element_max_heap(std::vector<int> &src) {
  if (src.empty()) {
    std::cout << "El heap está vacío.\n";
    return;
  }

  std::swap(src[0],
            src[src.size() - 1]);
  src.pop_back();

  int pos = 0;
  int size = src.size();

  while (true) {
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    int largest = pos;

    if (left < size && src[left] > src[largest]) {
      largest = left;
    }

    if (right < size && src[right] > src[largest]) {
      largest = right;
    }

    if (largest == pos) {
      break;
    }

    std::swap(src[pos], src[largest]);
    pos = largest;
  }
}

void print(std::vector<int> src) {
  for (auto num : src)
    std::cout << num << "\n";
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  std::vector<int> heap_mem = {40, 35, 30, 15, 10, 25, 5};
  print(heap_mem);
  remove_element_max_heap(heap_mem);
  print(heap_mem);

  return 0;
}
