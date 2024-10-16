#include "../include/HashTable.h"
#include <iostream>

/**
 *
 *  Como declaramos el Nodo original de la hash table con doble puntero, lo que
 * haremos es asignar el tamaño especificado para la hash table.
 *  Entonces, reservamos un espacio de 10 nodos. Un hash que apunta a una lista
 * de nodos.
 *
 */
HashTable::HashTable() {
  HT = new Node *[10];
  for (int i = 0; i < 10; i++) {
    HT[i] = nullptr;
  }
}

int HashTable::Hash(int key) { return key % 10; }

void HashTable::Insert(int key) {
  int hash_idx = Hash(key);
  Node *tmp = new Node;
  // nodo temporal donde almaceno el valor de la lleva
  tmp->data = key;
  tmp->next = nullptr;

  if (!HT[hash_idx])
    HT[hash_idx] = tmp;
  else {
    // este puntero apunta a los valores
    Node *p = HT[hash_idx];
    // este puntero recorre la HT para conocer la posición donde vamos a
    // insertar.
    Node *q = HT[hash_idx];
    // intercambiamos los valores hasta que podamos encontrar el lugar adecuado.
    while (p && p->data < key) {
      q = p;
      p = p->next;
    }
    if (q == HT[hash_idx]) {
      //
      tmp->next = HT[hash_idx];
      HT[hash_idx] = tmp;
    } else {
      tmp->next = q->next;
      q->next = tmp;
    }
  }
}

void HashTable::Print() {


}

int HashTable::Search(int key) {
  int hash_idx = Hash(key);
  Node *p = HT[hash_idx];
  while (p) {
    if (p->data == key) {
      return p->data;
    }
    p = p->next;
  }

  return -1;
}
/* HashTable::~HashTable() {
  for (int i = 0; i < 10; i++) {
    while(HT[i]){

    }
  }
}*/
