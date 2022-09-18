#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestContinuousSubstring(string s) {
    int answer = 1;

    int current = 1;
    int prev_char = s[0];
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == prev_char + 1) {
        current++;
      } else {
        answer = max(answer, current);
        current = 1;
      }
      prev_char = s[i];
    }

    answer = max(answer, current);

    return answer;
  }
};

int main() {
  return 0;
}
