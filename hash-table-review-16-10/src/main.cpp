#include "../include/HashTable.h"
#include <iostream>
int main(int argc, char *argv[]) {

  int A[] = {16, 12, 25, 39, 6, 122, 56, 68, 75};
  int A_size = sizeof(A) / sizeof(A[0]);

  HashTable H;
  for (int i = 0; i < A_size; i++) {
    H.Insert(A[i]);
  }
  std::cout<<H.Search(20)<<"\n";
  std::cout<<H.Search(6)<<"\n";
  return 0;
}
