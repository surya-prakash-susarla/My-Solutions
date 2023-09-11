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

  vvint memo;

  int __rec__(int si, int ti, const string& source, const string& target) {
    if (ti == target.size())
      return source.size() - si;

    if (si == source.size())
      return target.size() - ti;

    if (memo[si][ti] != -1)
      return memo[si][ti];

    constexpr int maxvalue = numeric_limits<int>::max();
    int incl = maxvalue;
    if (source[si] == target[ti]) {
      incl = __rec__(si + 1, ti + 1, source, target);
    }

    int excl_no_swap = __rec__(si + 1, ti, source, target) + 1;
    int excl_swap = __rec__(si + 1, ti + 1, source, target) + 1;
    int incl_add_curr = __rec__(si, ti + 1, source, target) + 1;

    memo[si][ti] = min({incl, excl_no_swap, excl_swap, incl_add_curr});

    return memo[si][ti];
  }

  int minDistance(string source, string target) {
    memo = vvint(source.size(), vint(target.size(), -1));
    return __rec__(0, 0, source, target);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
