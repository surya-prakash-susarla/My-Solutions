#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string optimalDivision(vector<int>& input) {
    if (input.size() == 0)
      return string();
    if (input.size() == 1)
      return to_string(input[0]);
    string answer = to_string(input[0]) + "/";
    if (input.size() == 2)
      answer = answer + to_string(input[1]);
    else {
      answer = answer + '(';
      for (int i = 1; i < input.size() - 1; i++) {
        answer = answer + to_string(input[i]) + '/';
      }
      answer = answer + to_string(input[input.size() - 1]) + ')';
    }
    return answer;
  }
};