#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string baseNeg2(int input) {
    if (input == 0)
      return "0";
    string answer;
    while (input != 1 and input != -1 and input != 0) {
      int rem, nxt_value;
      rem = abs(input) % 2;
      if (input < 0)
        nxt_value = abs(input) / 2;
      else
        nxt_value = 0 - input / 2;
      if (input < 0 and rem == 1)
        nxt_value += 1;
      input = nxt_value;
      answer = answer + (char)(rem + '0');
    }
    if (input == 1)
      answer = answer + '1';
    else if (input == -1)
      answer = answer + "11";
    reverse(answer.begin(), answer.end());
    return answer;
  }
};