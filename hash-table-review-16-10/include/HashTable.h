#include "Node.h"
#ifndef HASHTABLE_H
#define HASHTABLE_H
class HashTable {
public:
  Node **HT;
  HashTable();
  int Hash(int key);
  void Insert(int key);
  int Search(int key);
  void Print();
 // ~HashTable();
};
#endif // !HASTABLE_H
