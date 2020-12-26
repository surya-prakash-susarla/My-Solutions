#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> answer;

  void calc(int pairs, int rem, string value) {
    if (pairs == 0) {
      value += string(rem, ')');
      answer.push_back(value);
      return;
    }
    if (rem != 0)
      calc(pairs, rem - 1, value + ')');
    calc(pairs - 1, rem + 1, value + '(');
    return;
  }

  vector<string> generateParenthesis(int n) {
    calc(n, 0, string());
    return answer;
  }
};