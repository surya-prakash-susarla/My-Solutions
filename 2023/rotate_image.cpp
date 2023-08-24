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
  typedef pair<int, int> pint;

  // dir
  // 0 -> left , 1 -> down , 2 -> right , 3 -> up

  pint get_next_loc(int i,
                    int j,
                    int dir,
                    int n,
                    const pint& r,
                    const pint& c) {
    switch (dir) {
      case 0:
        return {r.first + (n - (c.second - j + 1)), c.second};
      case 1:
        return {r.second, c.second - (n - (r.second - i + 1))};
      case 2:
        return {r.second - (n - (j - c.first + 1)), c.first};
      case 3:
      default:
        return {r.first, c.first + (n - (i - r.first + 1))};
    }
  }

  inline int get_next_dir(int dir) { return (dir + 1) % 4; }

  void __rec__(int i,
               int j,
               int dir,
               int n,
               const pint& r,
               const pint& c,
               vvint& ref) {
    constexpr int null = numeric_limits<int>::min();
    if (ref[i][j] == null)
      return;

    int current = ref[i][j];
    ref[i][j] = null;
    pint next = get_next_loc(i, j, dir, n, r, c);
    __rec__(next.first, next.second, get_next_dir(dir), n, r, c, ref);
    ref[next.first][next.second] = current;
    return;
  }

  void rotate(vector<vector<int>>& input) {
    int n = input.size();
    for (int i = 0; i < n / 2; i++) {
      int size = n - 2 * i;
      for (int j = i; j < i + size - 1; j++)
        __rec__(i, j, 0, size, {i, i + size - 1}, {i, i + size - 1}, input);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
