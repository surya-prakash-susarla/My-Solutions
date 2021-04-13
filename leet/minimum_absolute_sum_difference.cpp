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

#include <bits/stdc++.h>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  unordered_map<int, int> memo;

  inline int __dist__(const int a, const int b) { return abs(a - b); }

  int __find__(const int target, const int parent, const set<int>& values) {
    unordered_map<int, int>::iterator mit = memo.find(target);
    if (mit != memo.end())
      return mit->second;

    set<int>::iterator it = values.lower_bound(target);
    if (it == values.begin() || it == values.end()) {
      const int result =
          it == values.end() ? *values.rbegin() : *values.begin();
      if (__dist__(parent, target) > __dist__(result, target))
        memo[target] = result;
      else
        memo[target] = parent;
      return memo[target];
    }

    const int ub = *it;
    advance(it, -1);
    const int lb = *it;

    const int udiff = __dist__(ub, target);
    const int ldiff = __dist__(lb, target);
    const int cdiff = __dist__(parent, target);

    const int answer = min({udiff, ldiff, cdiff});

    if (answer == cdiff)
      memo[target] = parent;
    else if (answer == ldiff)
      memo[target] = lb;
    else
      memo[target] = ub;

    return memo[target];
  }

  int minAbsoluteSumDiff(vector<int>& input1, vector<int>& input2) {
    set<int> values(input1.begin(), input1.end());

    constexpr int modval = 1000000007;

    int maxdist = -1;
    int mi = -1;
    int target_dist = -1;

    for (int i = 0; i < input1.size(); i++) {
      const int current_dist = __dist__(input1[i], input2[i]) % modval;
      const int replacement = __find__(input2[i], input1[i], values);
      const int replacement_dist = __dist__(replacement, input2[i]) % modval;

      if (maxdist < (current_dist - replacement_dist)) {
        maxdist = current_dist - replacement_dist;
        mi = i;
        target_dist = replacement_dist;
      }
    }

    int sum = 0;
    for (int i = 0; i < input1.size(); i++) {
      int cd = i == mi ? target_dist : __dist__(input1[i], input2[i]);
      cd %= modval;
      sum += cd;
      sum %= modval;
    }

    return sum;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
