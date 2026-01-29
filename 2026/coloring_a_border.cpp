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

  int mod_color = -1;
  int og_color = -1;
  int used = INT_MAX;

  bool should_paint(int i, int j, const vvint& original) {
    if (original[i][j] != og_color)
      return false;

    bool left = is_edge(i, j - 1, original);
    bool right = is_edge(i, j + 1, original);
    bool top = is_edge(i - 1, j, original);
    bool down = is_edge(i + 1, j, original);

    return left or right or top or down;
  }

  bool is_edge(int i, int j, const vvint& original) {
    if (i < 0 or j < 0 or i >= original.size() or j >= original[0].size())
      return true;
    if (original[i][j] != og_color and original[i][j] != used)
      return true;
    return false;
  }

  void fill(int i, int j, vvint& original, vvint& mod) {
    if (i < 0 or j < 0 or i >= original.size() or j >= original[0].size())
      return;

    if (original[i][j] == used or original[i][j] != og_color)
      return;

    if (should_paint(i, j, original)) {
      mod[i][j] = mod_color;
    }

    // mark visited.
    original[i][j] = used;

    fill(i - 1, j, original, mod);
    fill(i + 1, j, original, mod);
    fill(i, j + 1, original, mod);
    fill(i, j - 1, original, mod);
  }

  vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                  int row,
                                  int col,
                                  int color) {
    vvint mod = grid;
    mod_color = color;
    og_color = grid[row][col];

    fill(row, col, grid, mod);

    return mod;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
