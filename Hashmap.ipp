#ifndef HASHMAP_IPP
#define HASHMAP_IPP

#include "Hashmap.h"

template <typename K, typename V>
HashMap<K, V>::HashMap(size_t initial_capacity) {
  this->capacity = initial_capacity;
  this->buckets = new Node*[capacity]();
  this->num_of_elements = 0;
}

template <typename K, typename V>
HashMap<K, V>::~HashMap() {
  for (size_t i = 0; i < this->capacity; i++) {
    Node* curr = this->buckets[i];
    while (curr) {
      Node* temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
  delete[] this->buckets;
}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
  int index = hash(key);
  Node* curr = this->buckets[index];

  //this is the linked list traversal we spoke of
  while (curr) {
    if (curr->key == key) {
      curr->value = value;
      return;
    }
    curr = curr->next;
  }

  Node* new_node = new Node(key, value, buckets[index]);
  this->buckets[index] = new_node;
  this->num_of_elements++;

  if (static_cast<double>(num_of_elements) / capacity > MAX_LOAD_FACTOR) {
    rehash();
  }
}

template <typename K, typename V>
bool HashMap<K, V>::erase(const K& key) {
  int target = hash(key);
  Node* curr = this->buckets[target];
  if (!curr) return false;
  if (curr->key == key) {
    this->buckets[target] = curr->next;
  	delete curr;
  	this->num_of_elements--;
  	return true;
  }
  while (curr->next) {
    if (curr->next->key == key) {
      Node* temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
      this->num_of_elements--;
      return true;
    } else {
      curr = curr->next;
    }
  }
  return false;
}

// Attempts to locate specified key and returns either the key value or nullptr if key isn't in map
template <typename K, typename V>
V* HashMap<K, V>::find(const K& key) {
  int target = hash(key);
  Node* curr = this->buckets[target];
  while (curr) {
    if (curr->key == key) {
      return &curr->value;
    }
    curr = curr->next;
  }
  return nullptr;
}

// Returns the size of HashMap
template <typename K, typename V>
size_t HashMap<K, V>::size() const {
  return this->num_of_elements;
}

// Returns true or false on whether HashMap is empty
template <typename K, typename V>
bool HashMap<K, V>::empty() const {
  return this->num_of_elements == 0;
}

//remove all key-value pairs
//free the memory
template <typename K, typename V>
void HashMap<K, V>::clear() {
  if (this->num_of_elements == 0) { return; }
  //loop through the array and then traverse the linked lists, then just delete, then set num_of_elements
  for (size_t i = 0; i < this->capacity; i++) {
    Node* curr = this->buckets[i];
    while (curr) {
      Node* temp = curr;
      curr = curr->next;
      delete temp;
    }
    this->buckets[i] = nullptr;
  }
  this->num_of_elements = 0;
}

//print capacity, number of elements, how full table is (numelemtns / capactiy),
template <typename K, typename V>
void HashMap<K, V>::print_stats() const {
  std::cout << "Capacity: " << this->capacity << std::endl;
  std::cout << "Size: " << this->num_of_elements << std::endl;
  std::cout << "How full (percentage): " << static_cast<double>(this->num_of_elements) /this->capacity << std::endl;
  int empty_buckets = 0;
  for (size_t i = 0; i < this->capacity; i++) {
    if (this->buckets[i] == nullptr) {
      empty_buckets++;
    }
  }
  std::cout << "Empty buckets: " << empty_buckets << std::endl;
}

template <typename K, typename V>
int HashMap<K, V>::hash(const K& key) const {
  return static_cast<unsigned>(key) % capacity;
}

template <typename K, typename V>
void HashMap<K, V>::rehash() {
  Node** old_buckets = this->buckets;
  size_t old_capacity = this->capacity;

  this->capacity *= 2;
  this->buckets = new Node*[this->capacity]();
  this->num_of_elements = 0;

  for (size_t i = 0; i < old_capacity; i++) {
    Node* curr = old_buckets[i];
    while (curr) {
      Node* next = curr->next;
      insert(curr->key, curr->value);
      delete curr;
      curr = next;
    }
  }
  delete[] old_buckets;
}

#endif