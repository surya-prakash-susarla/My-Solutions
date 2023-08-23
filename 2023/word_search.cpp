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
  typedef vector<bool> vbool;
  typedef vector<vbool> vvbool;

#define valid(x)           \
  if (x) {                 \
    visited[i][j] = false; \
    return true;           \
  }

  string value;
  vector<vector<char>> input;
  int m;
  int n;

  bool __rec__(int i, int j, int ind, vvbool& visited) {
    if (ind == value.size())
      return true;

    if (i < 0 or j < 0 or i >= m or j >= n)
      return false;

    if (input[i][j] != value[ind])
      return false;
    if (visited[i][j])
      return false;

    visited[i][j] = true;

    valid(__rec__(i, j - 1, ind + 1, visited));
    valid(__rec__(i + 1, j, ind + 1, visited));
    valid(__rec__(i, j + 1, ind + 1, visited));
    valid(__rec__(i - 1, j, ind + 1, visited));

    visited[i][j] = false;
    return false;
  }

  bool exist(vector<vector<char>>& input, string value) {
    this->value = value;
    this->input = input;
    m = input.size();
    n = input[0].size();

    vvbool memo(m, vbool(n));

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (__rec__(i, j, 0, memo))
          return true;

    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
