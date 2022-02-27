#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    typedef optional<int> oint;
    map<char, oint> locations;
    int answer = 0;
    int bindex = 0;
    int current_length = 0;
    for (int i = 0; i < s.size(); i++) {
      oint current_state = locations[s[i]];
      if (current_state.has_value() and current_state.value() >= bindex) {
        current_length = i - current_state.value();
        locations[s[i]] = i;
        bindex = current_state.value() + 1;
        answer = max(answer, current_length);
      } else {
        locations[s[i]] = i;
        current_length++;
        answer = max(answer, current_length);
      }
    }
    return answer;
  }
};
