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

class MovingAverage {
 public:
  queue<int> values;
  int sumvalue = 0;
  int k;

  MovingAverage(int size) { k = size; }

  double next(int x) {
    if (values.size() < k) {
      values.push(x);
      sumvalue += x;
      return (double)(sumvalue) / values.size();
    } else {
      int old = values.front();
      values.pop();
      values.push(x);
      sumvalue -= old;
      sumvalue += x;
      return (double)(sumvalue) / k;
    }
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
