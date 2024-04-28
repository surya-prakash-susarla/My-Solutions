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
  void fill(int i, int j, vector<vector<char>>& values) {
    if (values[i][j] == '0')
      return;
    values[i][j] = '0';
    if (i - 1 > -1)
      fill(i - 1, j, values);
    if (j - 1 > -1)
      fill(i, j - 1, values);
    if (i + 1 < values.size())
      fill(i + 1, j, values);
    if (j + 1 < values[i].size())
      fill(i, j + 1, values);
  }

  int numIslands(vector<vector<char>>& grid) {
    int answer = 0;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          answer++;
          fill(i, j, grid);
        }
      }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
