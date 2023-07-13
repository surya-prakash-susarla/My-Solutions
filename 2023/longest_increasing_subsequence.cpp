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

class Solution {
 public:
  static constexpr int minvalue = numeric_limits<int>::min();
  static constexpr int maxvalue = numeric_limits<int>::max();

  vector<int> memo;

  int __rec__(int prev_value, int index, const vector<int>& values) {
    if (index == values.size())
      return 0;
    int incl = minvalue;
    if (prev_value < values[index]) {
      if (memo[index] != -1)
        incl = memo[index];
      else {
        memo[index] = 1 + __rec__(values[index], index + 1, values);
        incl = memo[index];
      }
    }
    int excl = __rec__(prev_value, index + 1, values);
    return max(incl, excl);
  }

  int lengthOfLIS(vector<int>& values) {
    memo = vector<int>(values.size(), -1);
    return __rec__(minvalue, 0, values);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
