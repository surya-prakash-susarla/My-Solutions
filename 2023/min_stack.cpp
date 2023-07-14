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
    int minvalue = index - 1 > -1 ? min(val, mins[index - 1]) : val;
    if (index == values.size()) {
      index++;
      values.push_back(val);
      mins.push_back(minvalue);
    } else {
      values[index] = val;
      mins[index] = minvalue;
      index++;
    }
  }

  void pop() { index--; }

  int top() { return values[index - 1]; }

  int getMin() { return mins[index - 1]; }

  int index = 0;
  vector<int> values;
  vector<int> mins;
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
