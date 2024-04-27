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
  int n;
  vector<int> active_min;

  void findMins() {
    vector<int> left(n, INT_MAX);
    vector<int> right(n, INT_MAX);

    for (int i = n - 2; i > -1; i--)
      left[i] = min(active_min[i + 1], left[i + 1]);

    for (int i = 1; i < n; i++)
      right[i] = min(active_min[i - 1], right[i - 1]);

    for (int i = 0; i < n; i++)
      active_min[i] = min(left[i], right[i]);
  }

  int minFallingPathSum(vector<vector<int>>& grid) {
    n = grid.size();

    active_min = grid[n - 1];
    if (n > 1)
      findMins();

    for (int i = n - 2; i > -1; i--) {
      for (int j = 0; j < n; j++)
        active_min[j] = grid[i][j] + active_min[j];

      if (i > 0)
        findMins();
    }

    int answer = INT_MAX;
    for (int i : active_min)
      answer = min(answer, i);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
