#include "Hashmap.h"

template <typename K, typename V>
HashMap<K, V>::HashMap(size_t initial_capacity) {}

template <typename K, typename V>
HashMap<K, V>::~HashMap() {}

template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {}

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
int HashMap<K, V>::hash(const K& key) {}

template <typename K, typename V>
void HashMap<K, V>::rehash() {}