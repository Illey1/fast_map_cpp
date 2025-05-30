#ifndef HASHMAP_IPP
#define HASHMAP_IPP

#include "Hashmap.h"

template <typename K, typename V>
HashMap<K, V>::HashMap(size_t initial_capacity) {
  capacity = initial_capacity;
}

template <typename K, typename V>
HashMap<K, V>::~HashMap() {}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
  int index = hash(key);
  Node* curr = buckets[index];

  //this is the linked list traversal we spoke of
  while (curr) {
    if (curr->key == key) {
      curr->value = value;
      return;
    }
    curr = curr->next;
  }

  Node* new_node = new Node(key, value, buckets[index]);
  buckets[index] = new_node;
  num_elements++;

  if (static_cast<double>(num_elements) / capacity > MAX_LOAD_FACTOR) {
    rehash();
  }
}

template <typename K, typename V>
bool HashMap<K, V>::erase(const K& key) {}

template <typename K, typename V>
V* HashMap<K, V>::find(const K& key) {}

template <typename K, typename V>
size_t HashMap<K, V>::size() const {}

template <typename K, typename V>
bool HashMap<K, V>::empty() const {}

template <typename K, typename V>
void HashMap<K, V>::clear() {}

template <typename K, typename V>
void HashMap<K, V>::print_stats() const {}

template <typename K, typename V>
int HashMap<K, V>::hash(const K& key) const {
  return static_cast<unsigned>(key) % capacity;
}

template <typename K, typename V>
void HashMap<K, V>::rehash() {}

#endif