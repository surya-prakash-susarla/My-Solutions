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

class ZeroEvenOdd {
 private:
  int n;
  int current = 0;

  mutex m;
  condition_variable c;

  bool print_odd_thread = false;
  bool print_even_thread = false;

  bool exit_odd_thread = false;
  bool exit_even_thread = false;

 public:
  ZeroEvenOdd(int n) { this->n = n; }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    current++;
    cout << "updated current to : " << current << endl;
    if (current > n) {
      cout << "attempting to stop threads" << endl;
      // exit odd thread
      {
        cout << "attempting to stop odd thread" << endl;
        unique_lock l(m);
        exit_odd_thread = true;
        print_odd_thread = true;
        c.notify_all();
        c.wait(l, [&] { return not print_odd_thread; });
        cout << "odd thread stopped" << endl;
      }
      // exit even thread
      {
        cout << "attempting to stop even thread" << endl;
        unique_lock l(m);
        exit_even_thread = true;
        print_even_thread = true;
        c.notify_all();
        c.wait(l, [&] { return not print_even_thread; });
        cout << "even thread stopped" << endl;
      }
      cout << "exiting zero function" << endl;
      return;
    }

    cout << "printing zero" << endl;
    printNumber(0);
    if (current % 2) {
      // unlock odd thread
      print_odd_thread = true;
      unique_lock l(m);
      cout << "unlocking odd thread" << endl;
      c.notify_all();
      c.wait(l, [&] { return not print_odd_thread; });
      cout << "returning to zero function" << endl;
    } else {
      // unlock even thread
      print_even_thread = true;
      unique_lock l(m);
      cout << "unlocking even thread" << endl;
      c.notify_all();
      c.wait(l, [&] { return not print_even_thread; });
      cout << "returning to zero function" << endl;
    }

    // recurse.
    cout << "recursing through the zero loop" << endl;
    zero(printNumber);
  }

  void even(function<void(int)> printNumber) {
    unique_lock l(m);
    c.wait(l, [&] { return print_even_thread; });

    cout << "printing even" << endl;
    print_even_thread = false;
    if (exit_even_thread) {
      cout << "notifying all about even exit" << endl;
      c.notify_all();
      return;
    }

    printNumber(current);

    l.unlock();

    cout << "notifying all about even completion" << endl;
    c.notify_all();

    cout << "recursing to keep thread alive" << endl;
    even(printNumber);
  }

  void odd(function<void(int)> printNumber) {
    unique_lock l(m);
    c.wait(l, [&] { return print_odd_thread; });

    cout << "printing odd" << endl;
    print_odd_thread = false;
    if (exit_odd_thread) {
      cout << "notifying all about odd exit" << endl;
      c.notify_all();
      return;
    }

    printNumber(current);

    l.unlock();

    cout << "notifying all about odd completion" << endl;
    c.notify_all();

    cout << "recursing to keep thread alive" << endl;
    odd(printNumber);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
