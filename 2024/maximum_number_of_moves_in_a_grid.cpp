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

  int find(int r, int c, const vvint& input) {
    if (c == n - 1)
      return 0;
    if (memo[r][c] != -1)
      return memo[r][c];

    int answer = 0;
    if (r - 1 > -1 and input[r - 1][c + 1] > input[r][c]) {
      answer = max(answer, 1 + find(r - 1, c + 1, input));
    }
    if (input[r][c + 1] > input[r][c]) {
      answer = max(answer, 1 + find(r, c + 1, input));
    }
    if (r + 1 < m and input[r + 1][c + 1] > input[r][c]) {
      answer = max(answer, 1 + find(r + 1, c + 1, input));
    }

    memo[r][c] = answer;

    return answer;
  }

  int maxMoves(vector<vector<int>>& input) {
    m = input.size();
    n = input[0].size();

    memo = vvint(m, vint(n, -1));

    int answer = 0;
    for (int i = 0; i < m; i++) {
      answer = max(answer, find(i, 0, input));
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
