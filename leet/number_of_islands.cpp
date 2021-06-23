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
  static constexpr char cc = '@';

  using vvc = vector<vector<char>>;
  using pint = pair<int, int>;

  static constexpr pint end = {-1, -1};

  int m, n;

  pint __ind__(const vvc& grid) {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == '1')
          return {i, j};
    return end;
  }

  void __update__(vvc& grid, pint ind) {
    if (ind.first < 0 or ind.first >= m or ind.second < 0 or ind.second >= n)
      return;
    if (grid[ind.first][ind.second] != '1')
      return;

    grid[ind.first][ind.second] = cc;
    __update__(grid, {ind.first - 1, ind.second});
    __update__(grid, {ind.first + 1, ind.second});
    __update__(grid, {ind.first, ind.second - 1});
    __update__(grid, {ind.first, ind.second + 1});
  }

  int numIslands(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int answer = 0;

    for (pint ind = __ind__(grid); ind != end; ind = __ind__(grid)) {
      __update__(grid, ind);
      answer++;
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
