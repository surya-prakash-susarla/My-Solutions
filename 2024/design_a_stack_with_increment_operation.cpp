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

class CustomStack {
 public:
  CustomStack(int size) {
    values = vector<int>(size, 0);
    inc = vector<int>(size, 0);
  }

  void push(int x) {
    if (current == values.size() - 1)
      return;
    values[++current] = x;
  }

  int pop() {
    if (current == -1)
      return -1;
    int value = values[current] + inc[current];
    inc[current--] = 0;
    return value;
  }

  void increment(int k, int val) {
    for (int i = 0; i <= current and i < k; i++)
      inc[i] += val;
  }

  vector<int> values;
  vector<int> inc;
  int current = -1;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
