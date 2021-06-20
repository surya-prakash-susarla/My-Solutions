#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int answer = 0;

  void findPath(int x,
                int y,
                int count,
                vector<vector<int>>& value,
                const int& req) {
    if (x < 0 or y < 0 or x == value.size() or y == value[0].size() or
        value[x][y] == -1 or value[x][y] == 3)
      return;
    if (value[x][y] == 2) {
      if (count == req)
        answer += 1;
      return;
    }
    int temp = value[x][y];
    // mark visited
    value[x][y] = 3;
    findPath(x, y + 1, count + 1, value, req);
    findPath(x, y - 1, count + 1, value, req);
    findPath(x + 1, y, count + 1, value, req);
    findPath(x - 1, y, count + 1, value, req);
    value[x][y] = temp;
    return;
  }

  int uniquePathsIII(vector<vector<int>>& grid) {
    int init_x, init_y, req = 0;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if (grid[i][j] == 0)
          req += 1;
        else if (grid[i][j] == 1)
          init_x = i, init_y = j;
    findPath(init_x, init_y, -1, grid, req);
    return this->answer;
  }
};