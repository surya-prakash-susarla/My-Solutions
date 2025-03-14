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

  vvint input;
  int m;
  int n;

  int __rec__(int i, int j) {
    if (i < 0 or j < 0 or i >= m or j >= n)
      return 0;

    if (memo[i][j] != -1)
      return memo[i][j];

    const int value = input[i][j];
    int answer = 1;
    if (i - 1 > -1 and value < input[i - 1][j])
      answer = max(answer, 1 + __rec__(i - 1, j));
    if (j - 1 > -1 and value < input[i][j - 1])
      answer = max(answer, 1 + __rec__(i, j - 1));
    if (i + 1 < m and value < input[i + 1][j])
      answer = max(answer, 1 + __rec__(i + 1, j));
    if (j + 1 < n and value < input[i][j + 1])
      answer = max(answer, 1 + __rec__(i, j + 1));

    memo[i][j] = answer;
    return answer;
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    input = matrix;
    m = input.size();
    n = input[0].size();

    memo = vvint(m, vint(n, -1));

    int answer = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        const int current = __rec__(i, j);
        answer = max(answer, current);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
