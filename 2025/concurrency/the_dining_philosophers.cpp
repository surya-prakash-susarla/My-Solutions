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

class DiningPhilosophers {
 public:
  DiningPhilosophers() { fa = vector<bool>(5, true); }

  void wantsToEat(int p,
                  function<void()> pickLeftFork,
                  function<void()> pickRightFork,
                  function<void()> eat,
                  function<void()> putLeftFork,
                  function<void()> putRightFork) {
    unique_lock l(m);
    c.wait(l, [&] { return fa[p] && fa[(p + 4) % 5]; });

    fa[p] = false;
    fa[(p + 4) % 5] = false;

    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();

    fa[p] = true;
    fa[(p + 4) % 5] = true;

    c.notify_all();
  }

  vector<bool> fa;

  mutex m;
  condition_variable c;
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
