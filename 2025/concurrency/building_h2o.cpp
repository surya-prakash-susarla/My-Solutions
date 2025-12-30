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

class H2O {
 public:
  atomic<int> h = 2;
  atomic<int> o = 0;

  mutex m;
  condition_variable c;

  H2O() {}

  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock l(m);
    cout << "waiting hydro" << endl;
    c.wait(l, [&] { return h.load(); });

    cout << "printing hydro" << endl;
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();

    h--;
    if (h == 0) {
      cout << "setting oxy" << endl;
      o = 1;
    }
    c.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock l(m);
    cout << "waiting oxy" << endl;
    c.wait(l, [&] { return o.load(); });

    cout << "printing oxy" << endl;
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();

    cout << "setting hydro" << endl;
    o = 0;
    h = 2;
    c.notify_all();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
