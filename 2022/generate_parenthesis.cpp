#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  set<string> answer;

  void __calc__(string current, int open, int close) {
    if (open == 0) {
      answer.insert(current + string(close, ')'));
      return;
    }
    if (open > 0) {
      __calc__(current + '(', open - 1, close + 1);
    }
    if (close > 0) {
      __calc__(current + ')', open, close - 1);
    }
  }

  vector<string> generateParenthesis(int n) {
    __calc__(string(), n, 0);
    return vector<string>(answer.begin(), answer.end());
  }
};
