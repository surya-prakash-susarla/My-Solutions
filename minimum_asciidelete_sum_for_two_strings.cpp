#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calc(int i,
           int j,
           const string& a,
           const string& b,
           vector<vector<int>>& memo) {
    int cost = 0;

    if (i == a.size()) {
      if (j == b.size())
        return 0;
      while (j < b.size())
        cost += (int)b[j++];
      return cost;
    }
    if (j == b.size()) {
      if (i == a.size())
        return 0;
      while (i < a.size())
        cost += (int)a[i++];
      return cost;
    }

    if (memo[i][j] != -1)
      return memo[i][j];

    // delete character in a and b
    cost = calc(i + 1, j, a, b, memo) + (int)a[i];
    cost = min(cost, calc(i, j + 1, a, b, memo) + (int)b[j]);

    if (a[i] == b[j])
      cost = min(cost, calc(i + 1, j + 1, a, b, memo));
    else
      cost = min(cost, calc(i + 1, j + 1, a, b, memo) + (int)a[i] + (int)b[j]);

    memo[i][j] = cost;
    return memo[i][j];
  }

  int minimumDeleteSum(string a, string b) {
    vector<vector<int>> memo(a.size(), vector<int>(b.size(), -1));
    int answer = calc(0, 0, a, b, memo);
    return answer;
  }
};