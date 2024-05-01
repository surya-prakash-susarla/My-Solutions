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
  MinStack() {}

  void push(int val) {
    values.push(val);
    if (minvalues.empty())
      minvalues.push(val);
    else
      minvalues.push(min(this->getMin(), val));
  }

  void pop() {
    values.pop();
    minvalues.pop();
  }

  int top() { return values.top(); }

  int getMin() { return minvalues.top(); }

  stack<int> values;
  stack<int> minvalues;
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
