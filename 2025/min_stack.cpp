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

class MinStack {
 public:
  stack<pair<int, int>> values;

  MinStack() {}

  void push(int val) {
    if (values.empty()) {
      values.push(make_pair(val, val));
    } else {
      values.push(make_pair(val, min(val, values.top().second)));
    }
  }

  void pop() { values.pop(); }

  int top() { return values.top().first; }

  int getMin() { return values.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
