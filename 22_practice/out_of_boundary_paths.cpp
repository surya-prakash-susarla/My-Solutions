#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findPaths(int r, int c, int maxMove, int startRow, int startColumn) {
    memo = vector<vector<map<int, int>>>(r, vector<map<int, int>>(c));
    m = r;
    n = c;
    int answer = _calc(startRow, startColumn, maxMove);
    cout << "total cache hits : " << cache << endl;
    cout << "total depth : " << depth << endl;
    return answer;
  }

  int _calc(int i, int j, int moves) {
    if (i < 0 or i >= m or j < 0 or j >= n)
      return 1;
    if (moves <= 0)
      return 0;

    map<int, int>& ref = memo[i][j];
    auto it = ref.find(moves);
    if (it != ref.end()) {
      cache++;
      return it->second;
    }
    depth++;
    constexpr int mod = 1000000007;

    int answer = 0;
    answer += _calc(i - 1, j, moves - 1);
    answer %= mod;
    answer += _calc(i + 1, j, moves - 1);
    answer %= mod;
    answer += _calc(i, j - 1, moves - 1);
    answer %= mod;
    answer += _calc(i, j + 1, moves - 1);
    answer %= mod;

    memo[i][j][moves] = answer;
    return answer;
  }

  int m;
  int n;
  int cache = 0;
  int depth = 0;
  vector<vector<map<int, int>>> memo;
};
