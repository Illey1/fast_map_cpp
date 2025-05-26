#ifndef HASHMAP_CPP
#define HASHMAP_CPP

using namespace std;

template <typename Key, typename Value>
class HashMap {
public:
    HashMap();
    void insert(const Key&, const Value&);
    bool erase(const Key&);
    Value* find(const Key&);
    size_t size() const;
    bool empty() const;
    void clear();
    void print_stats();
private:
};

#endif