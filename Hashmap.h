#ifndef HASHMAP_H
#define HASHMAP_H

#include <cstddef>
#include <iostream>

template <typename K, typename V>
class HashMap {
public:
    HashMap(size_t initial_capacity = 16); //default capacity will be 16
    virtual ~HashMap(); //frees memory for all nodes and buckets

    void insert(const K& key, const V& value); //adds or updates key-value pair
    bool erase(const K& key); //removes key, if found returns true
    V* find(const K& key); //return pointer to value, if not found return nullptr

    size_t size() const; //total number of key-value pairs
    bool empty() const; //returns true if map has no elements, we can use linked list logic for this potentially
    void clear(); //remove all entries, we can call this in the destructor
    void print_stats() const;

private:
  //this will be our container under the cover, each bucket will be a linkedlist of these nodes
  struct Node {
    K key;
    V value;
    Node* next;

    Node(const K& key, const V& value, Node* n = nullptr)
        : key(key), value(value), next(n) {}
  };

  Node** buckets; //arrray of heads of each linked list
  size_t capacity; //total number of buckets
  size_t num_of_elements; //number of key-value pairs

  static constexpr double MAX_LOAD_FACTOR = 0.75;

  int hash(const K& key); //hashes key to index
  void rehash();// doubles capacity and inserts into new array for resizing


  //copy protection, don't worry about this yet i am not too familiar with this
  HashMap(const HashMap&) = delete;
  HashMap& operator=(const HashMap&) = delete;
};

#include "Hashmap.ipp"

#endif