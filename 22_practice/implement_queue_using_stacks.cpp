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

class MyQueue {
 public:
  stack<int> values_1;
  MyQueue() {}

  void push(int x) { values_1.push(x); }

  int pop() {
    stack<int> values_2;
    while (not values_1.empty()) {
      values_2.push(values_1.top());
      values_1.pop();
    }
    int return_value = values_2.top();
    values_2.pop();
    while (not values_2.empty()) {
      values_1.push(values_2.top());
      values_2.pop();
    }
    return return_value;
  }

  int peek() {
    stack<int> values_2;
    while (not values_1.empty()) {
      values_2.push(values_1.top());
      values_1.pop();
    }
    int return_value = values_2.top();
    while (not values_2.empty()) {
      values_1.push(values_2.top());
      values_2.pop();
    }
    return return_value;
  }

  bool empty() { return values_1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
