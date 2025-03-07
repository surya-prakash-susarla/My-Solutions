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
  vector<vector<int>> memo;

  int __rec__(int index, int is_first_incl, const vector<int>& values) {
    if (index >= values.size())
      return 0;
    int& ref = memo[index][is_first_incl];
    if (ref != -1)
      return ref;

    if (index == values.size() - 1) {
      if (is_first_incl)
        return 0;
      else
        return values[index];
    } else {
      int incl = values[index] + __rec__(index + 2, is_first_incl, values);
      int excl = __rec__(index + 1, is_first_incl, values);
      ref = max(incl, excl);
      return ref;
    }
  }

  int rob(vector<int>& values) {
    memo = vector<vector<int>>(values.size(), vector<int>(2, -1));

    int z_incl = values[0] + __rec__(2, true, values);
    int z_excl = __rec__(1, false, values);

    return max(z_incl, z_excl);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
