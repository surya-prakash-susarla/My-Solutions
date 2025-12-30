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

class BoundedBlockingQueue {
 public:
  BoundedBlockingQueue(int capacity) { n = capacity; }

  void enqueue(int element) {
    unique_lock l(m);
    c.wait(l, [&] { return values.size() < n; });

    values.push(element);
    c.notify_all();
  }

  int dequeue() {
    unique_lock l(m);
    c.wait(l, [&] { return not values.empty(); });

    int t = values.front();
    values.pop();

    c.notify_all();
    return t;
  }

  int size() { return values.size(); }

  int n;
  queue<int> values;
  mutex m;
  condition_variable c;
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
