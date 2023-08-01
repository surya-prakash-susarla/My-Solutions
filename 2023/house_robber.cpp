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
  int n;
  typedef vector<int> vint;

  vint memo;

  int __rec__(int index, const vint& values) {
    if (index >= values.size())
      return 0;

    if (memo[index] != -1)
      return memo[index];

    int incl = values[index] + __rec__(index + 2, values);
    int excl = __rec__(index + 1, values);

    memo[index] = max(incl, excl);

    return memo[index];
  }

  int rob(vector<int>& values) {
    if (values.size() <= 2)
      return *max_element(values.begin(), values.end());

    n = values.size();
    memo = vint(n, -1);

    __rec__(0, values);

    return *max_element(memo.begin(), memo.end());
  }
};
int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
