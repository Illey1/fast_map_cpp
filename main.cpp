#include "Hashmap.h"

int main() {
  HashMap<int,char> test(8);
  test.insert(1,'3');
  std::cout << *test.find(1) << std::endl;
  test.print_stats();

  return 0;
}