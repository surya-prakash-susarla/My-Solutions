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

class FooBar {
 private:
  int n;
  atomic<int> counter;

 public:
  FooBar(int n) {
    this->n = n;
    counter = 0;
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      while (counter % 2 != 0)
        this_thread::yield();
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      counter++;
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      while (counter % 2 != 1)
        this_thread::yield();
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      counter++;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
