#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Foo {
 public:
  Foo() {}

  void first(function<void()> printFirst) {
    while (current != 0)
      this_thread::yield();
    printFirst();
    current++;
  }

  void second(function<void()> printSecond) {
    while (current != 1)
      this_thread::yield();
    printSecond();
    current++;
  }

  void third(function<void()> printThird) {
    while (current != 2)
      this_thread::yield();
    printThird();
    current++;
  }

 private:
  atomic<int> current = 0;
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
