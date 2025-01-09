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
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  int __calc__(const vvint& input, const int k) {
    const int n = input.size();
    const int m = input[0].size();

    constexpr int modval = 1000000007;

    typedef long long int llint;
    typedef unordered_map<int, llint> um;

    vector<um> current(m);
    // fill up last row.
    current[m - 1][input[n - 1][m - 1]] = 1;

    auto set_value = [&](um& ref, int key, int val) {
      auto it = ref.find(key);
      if (it != ref.end()) {
        it->second += val;
        it->second %= modval;
      } else {
        ref[key] = (val % modval);
      }
    };

    for (int i = m - 2; i > -1; i--)
      for (auto j : current[i + 1])
        set_value(current[i], input[n - 1][i] ^ j.first, j.second);

    for (int i = n - 2; i > -1; i--) {
      vector<um> next(m);
      for (auto k : current[m - 1])
        set_value(next[m - 1], input[i][m - 1] ^ k.first, k.second);

      for (int j = m - 2; j > -1; j--) {
        for (auto k : current[j])
          set_value(next[j], input[i][j] ^ k.first, k.second);

        for (auto k : next[j + 1])
          set_value(next[j], input[i][j] ^ k.first, k.second);
      }

      swap(current, next);
    }

    return current[0][k] % modval;
  }

  int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    return __calc__(grid, k);
  }
};
lass Solution {
 public:
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  int __calc__(const vvint& input, const int k) {
    const int n = input.size();
    const int m = input[0].size();

    constexpr int modval = 1000000007;

    typedef long long int llint;
    typedef unordered_map<int, llint> um;

    vector<um> current(m);
    // fill up last row.
    current[m - 1][input[n - 1][m - 1]] = 1;

    auto set_value = [&](um& ref, int key, int val) {
      auto it = ref.find(key);
      if (it != ref.end()) {
        it->second += val;
        it->second %= modval;
      } else {
        ref[key] = (val % modval);
      }
    };

    for (int i = m - 2; i > -1; i--)
      for (auto j : current[i + 1])
        set_value(current[i], input[n - 1][i] ^ j.first, j.second);

    for (int i = n - 2; i > -1; i--) {
      vector<um> next(m);
      for (auto k : current[m - 1])
        set_value(next[m - 1], input[i][m - 1] ^ k.first, k.second);

      for (int j = m - 2; j > -1; j--) {
        for (auto k : current[j])
          set_value(next[j], input[i][j] ^ k.first, k.second);

        for (auto k : next[j + 1])
          set_value(next[j], input[i][j] ^ k.first, k.second);
      }

      swap(current, next);
    }

    return current[0][k] % modval;
  }

  int countPathsWithXorValue(vector<vector<int>> & grid, int k) {
    return __calc__(grid, k);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
