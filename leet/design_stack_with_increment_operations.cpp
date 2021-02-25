#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>


// Problem: https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class CustomStack {
 public:
  CustomStack(int maxSize) { maxsize = maxSize; }

  void push(int x) {
    if (values.size() != maxsize)
      values.push_back(x);
  }

  int pop() {
    if (!values.empty()) {
      int retval = values.back();
      values.pop_back();
      return retval;
    }
      return -1;
  }

  void increment(int k, int val) {
    for (int i = 0; i < k and i < values.size(); i++)
      values[i] += val;
  }

  int maxsize = -1;
  vector<int> values;
};


int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
