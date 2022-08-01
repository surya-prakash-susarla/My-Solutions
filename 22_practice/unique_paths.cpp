#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    grid = vector<vector<int>>(m, vector<int>(n, -1));
    grid[m - 1][n - 1] = 1;
    return __calc__(0, 0, m, n);
  }

  int __calc__(int x, int y, const int& m, const int& n) {
    if (x >= m or y >= n)
      return 0;
    if (grid[x][y] != -1)
      return grid[x][y];
    grid[x][y] = __calc__(x + 1, y, m, n) + __calc__(x, y + 1, m, n);
    return grid[x][y];
  }

  vector<vector<int>> grid;
};