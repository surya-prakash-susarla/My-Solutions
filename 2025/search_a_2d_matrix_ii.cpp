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

  int target;

  bool s_row(int x, int y, int j, const vvint& input) {
    if (x > y) {
      return false;
    }
    int current = (x + y) / 2;
    if (input[current][j] == target)
      return true;
    else if (input[current][j] < target)
      return s_row(current + 1, y, j, input);
    else
      return s_row(x, current - 1, j, input);
  }

  bool s_col(int x, int y, int i, const vvint& input) {
    if (x > y)
      return false;
    int current = (x + y) / 2;
    if (input[i][current] == target)
      return true;
    else if (input[i][current] < target)
      return s_col(current + 1, y, i, input);
    else
      return s_col(x, current - 1, i, input);
  }

  bool searchMatrix(vector<vector<int>>& input, int target) {
    this->target = target;

    int i_d = -1;
    int j_d = -1;

    int m = input.size();
    int n = input[0].size();

    for (int i = m - 1, j = n - 1; i > -1 and j > -1; i--, j--) {
      if (input[i][j] > target) {
        i_d = i;
        j_d = j;
      } else if (input[i][j] == target) {
        return true;
      } else {
        break;
      }
    }

    for (int i = i_d, j = j_d; i < m and j < n; i++, j++) {
      if (s_row(0, i, j, input) or s_col(0, j, i, input))
        return true;
    }

    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
