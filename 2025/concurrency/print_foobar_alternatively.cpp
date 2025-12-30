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
  mutex m;
  condition_variable c;
  bool print_foo = true;

 public:
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      unique_lock l(m);
      c.wait(l, [&] { return print_foo; });

      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();

      print_foo = false;
      c.notify_one();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      unique_lock l(m);
      c.wait(l, [&] { return not print_foo; });

      // printBar() outputs "bar". Do not change or remove this line.
      printBar();

      print_foo = true;
      c.notify_one();
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
