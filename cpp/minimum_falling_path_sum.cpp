#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calc(int x,
           int y,
           int sum,
           vector<vector<int>>& memo,
           const vector<vector<int>>& input) {
    if (x == input.size() or y < 0 or y == input[0].size())
      return numeric_limits<int>::max();
    if (x == input.size() - 1)
      return sum + input[x][y];
    if (memo[x][y] != numeric_limits<int>::max())
      return memo[x][y];
    memo[x][y] = input[x][y] + min(calc(x + 1, y, 0, memo, input),
                                   min(calc(x + 1, y - 1, 0, memo, input),
                                       calc(x + 1, y + 1, 0, memo, input)));
    return memo[x][y];
  }

  int minFallingPathSum(vector<vector<int>>& input) {
    if (input.size() == 0)
      return 0;
    int min_value = numeric_limits<int>::max();
    vector<vector<int>> memo(
        input.size(), vector<int>(input[0].size(), numeric_limits<int>::max()));
    for (int i = 0; i < input.size(); i++)
      min_value = min(min_value, calc(0, i, 0, memo, input));
    return min_value;
  }
};