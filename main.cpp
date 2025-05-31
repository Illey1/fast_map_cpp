#include "Hashmap.h"

int main() {
  std::cout << "hi";
  HashMap<int,char> test(8);
  std:: cout << "hi1";
  test.insert(1,'3');
  std::cout << "hi2";
  if (!test.find(1)) {
    std::cout << "not found";
    return 0;
  }
  std::cout<<"hi3";
  std::cout << *test.find(2);


  return 0;
}