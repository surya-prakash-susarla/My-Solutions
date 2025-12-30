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

class FizzBuzz {
 private:
  int n;

  int i = 1;
  bool exit = false;

  mutex m;
  condition_variable c;

 public:
  FizzBuzz(int n) { this->n = n; }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    unique_lock l(m);
    cout << "fizz waiting before lock" << endl;
    c.wait(l, [&] { return exit or (i % 3 == 0 and i % 5 != 0); });

    if (not exit)
      printFizz();

    cout << "printing fizz" << endl;
    i++;
    if (i > n)
      exit = true;
    l.unlock();
    c.notify_all();

    cout << "exit value : " << exit << endl;
    if (not exit)
      fizz(printFizz);
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    unique_lock l(m);
    cout << "buzz waiting before lock" << endl;
    c.wait(l, [&] { return exit or (i % 3 != 0 and i % 5 == 0); });

    if (not exit)
      printBuzz();

    cout << "printing buzz" << endl;
    i++;
    if (i > n)
      exit = true;
    l.unlock();
    c.notify_all();

    cout << "exit value : " << exit << endl;
    if (not exit)
      buzz(printBuzz);
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    unique_lock l(m);
    cout << "fizzbuzz waiting before lock" << endl;
    c.wait(l, [&] { return exit or (i % 5 == 0 and i % 3 == 0); });

    cout << "printing fizzbuzz" << endl;
    if (not exit)
      printFizzBuzz();

    i++;
    if (i > n)
      exit = true;
    l.unlock();
    c.notify_all();

    cout << "exit value : " << exit << endl;
    if (not exit)
      fizzbuzz(printFizzBuzz);
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    unique_lock l(m);
    cout << "number waiting before lock" << endl;
    c.wait(l, [&] { return exit or (i % 5 != 0 and i % 3 != 0); });

    cout << "printing number : " << i << endl;
    if (not exit)
      printNumber(i);

    i++;
    if (i > n)
      exit = true;
    l.unlock();
    c.notify_all();

    cout << "exit value : " << exit << endl;

    if (not exit)
      number(printNumber);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
