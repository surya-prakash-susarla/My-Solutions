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

  vvint memo;
  int m;
  int n;

  int __rec__(int x, int y, const vvint& input) {
    if (memo[x][y] != -1)
      return memo[x][y];

    constexpr int maxvalue = numeric_limits<int>::max();
    const int current = input[x][y];

    int right = x + 1 < m ? current + __rec__(x + 1, y, input) : maxvalue;
    int down = y + 1 < n ? current + __rec__(x, y + 1, input) : maxvalue;

    int answer = min(right, down);

    memo[x][y] = answer;

    return answer;
  }

  int minPathSum(vector<vector<int>>& input) {
    m = input.size();
    n = input[0].size();
    memo = vvint(m, vint(n, -1));

    memo[m - 1][n - 1] = input[m - 1][n - 1];

    return __rec__(0, 0, input);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
