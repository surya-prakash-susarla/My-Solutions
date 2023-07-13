#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  int numTrees(int n) {
    memo = vvint(n + 1, vint(n + 1, -1));
    return _calc(1, n);
  }

  int _calc(int start, int end) {
    if (start > end)
      return 1;
    if (end - start + 1 <= 2)
      return end - start + 1;
    if (memo[start][end] != -1)
      return memo[start][end];
    int answer = 0;
    for (int i = start; i <= end; i++) {
      int left = _calc(start, i - 1);
      int right = _calc(i + 1, end);
      answer += (left * right);
    }
    memo[start][end] = answer;
    return answer;
  }

  vvint memo;
};
