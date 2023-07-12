#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int movePath(int count, int x, int y, vector<vector<int>>& grid) {
    // cout << "current index : " << x << " " << y << endl ;
    if (grid[x][y] == 0 or grid[x][y] == -1)
      return count;
    if (x == 0 or y == 0 or x == grid.size() - 1 or y == grid[0].size() - 1)
      return -1;
    count += 1;
    grid[x][y] = -1;
    int left = movePath(0, x, y - 1, grid), right = movePath(0, x, y + 1, grid),
        top = movePath(0, x - 1, y, grid), bottom = movePath(0, x + 1, y, grid);
    if (left == -1 or right == -1 or top == -1 or bottom == -1)
      return -1;
    return count + left + right + top + bottom;
  }

  pair<int, int> findIndex(const vector<vector<int>>& input) {
    for (int i = 1; i < input.size() - 1; i++)
      for (int j = 1; j < input[0].size() - 1; j++)
        if (input[i][j] == 1)
          return {i, j};
    return {-1, -1};
  }

  int numEnclaves(vector<vector<int>>& grid) {
    int answer = 0;
    pair<int, int> index = findIndex(grid);
    while (index != make_pair(-1, -1)) {
      int current = movePath(0, index.first, index.second, grid);
      if (current != -1)
        answer += current;
      index = findIndex(grid);
    }
    return answer;
  }
};