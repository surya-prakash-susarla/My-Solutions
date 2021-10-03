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

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  typedef long long int llint;
  using olint = optional<llint>;
  bool error_for_last_hit_ = false;

  vector<vector<int>> values;
  int rmax = -1, cmax = -1;
  vector<vector<olint>> memo;

  void __print__() {
    cout << "state of memo" << endl;
    for (const vector<olint>& i : memo) {
      for (const olint& j : i) {
        j == nullopt ? cout << "null" : cout << j.value();
        cout << " ";
      }
      cout << endl;
    }
    return;
  }

  llint __min__(const olint a, const olint b) {
    if (a == nullopt and b == nullopt) {
      if (error_for_last_hit_)
        cout << "both are null - this is an ERROR" << endl;
      error_for_last_hit_ = true;
      return 0;
    }
    if (a == nullopt)
      return b.value();
    if (b == nullopt)
      return a.value();
    return min(a.value(), b.value());
  }

  olint __getval__(const int i, const int j) {
    if (i >= rmax or j >= cmax)
      return nullopt;
    if (!memo[i][j])
      __rec__(i, j);
    return memo[i][j];
  }

  void __rec__(int i, int j) {
    if (i >= rmax or j >= cmax)
      return;
    if (memo[i][j])
      return;
    olint right = __getval__(i, j + 1);
    olint down = __getval__(i + 1, j);

    llint minval = __min__(right, down);

    if (minval < 0)
      cout << "Somebody is returning a negative requirement - ERROR" << endl;
    int creq = values[i][j] - minval;
    if (creq < 0)
      creq = 0 - creq;
    else
      creq = 0;
    memo[i][j] = creq;
    return;
  }

  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    values = dungeon;
    rmax = values.size();
    cmax = values[0].size();
    memo = vector<vector<olint>>(rmax, vector<olint>(cmax));
    __rec__(0, 0);
    // __print__();
    return memo[0][0].value() + 1;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
