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
  mutex m;
  condition_variable c;
  int state = 1;

  Foo() { state = 1; }

  void first(function<void()> printFirst) {
    unique_lock l(m);
    c.wait(l, [&] { return state == 1; });

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    state = 2;

    l.unlock();
    c.notify_all();
  }

  void second(function<void()> printSecond) {
    unique_lock l(m);
    c.wait(l, [&] { return state == 2; });

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    state = 3;

    l.unlock();
    c.notify_all();
  }

  void third(function<void()> printThird) {
    unique_lock l(m);
    c.wait(l, [&] { return state == 3; });

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    state = 1;

    l.unlock();
    c.notify_all();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
