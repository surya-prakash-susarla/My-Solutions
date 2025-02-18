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
  int m;
  int n;

  typedef vector<int> vint;
  typedef vector<vint> vvint;

  vvint memo;

  int count(int i, int j) {
    if (i == m - 1 and j == n - 1)
      return 1;

    if (i < 0 or j < 0 or i >= m or j >= n)
      return 0;

    if (memo[i][j] != -1)
      return memo[i][j];

    memo[i][j] = count(i + 1, j) + count(i, j + 1);
    return memo[i][j];
  }

  int uniquePaths(int m, int n) {
    this->m = m;
    this->n = n;

    memo = vvint(m, vint(n, -1));

    return count(0, 0);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
