#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<char> char_type;
  vector<bool> is_repeat;

  vector<vector<int>> memo;

  bool __rec__(int string_index, int pattern_index, const string& input) {
    if (string_index == input.size()) {
      if (pattern_index == char_type.size())
        return true;
      if (is_repeat[pattern_index])
        return __rec__(string_index, pattern_index + 1, input);
      return false;
    }

    if (pattern_index == char_type.size())
      return false;

    if (memo[string_index][pattern_index] != -2)
      return (bool)(memo[string_index][pattern_index]);

    bool answer = false;
    // repeatable pattern
    if (is_repeat[pattern_index]) {
      if (char_type[pattern_index] == '.') {
        // options:
        // 1. include this and try to re-use
        // 2. include this and end
        // 3. exclude this
        answer = __rec__(string_index + 1, pattern_index, input) or
                 __rec__(string_index + 1, pattern_index + 1, input) or
                 __rec__(string_index, pattern_index + 1, input);
      } else {
        if (char_type[pattern_index] == input[string_index]) {
          // options:
          // 1. include this and try to re-use
          // 2. inlcude this and end
          answer = __rec__(string_index + 1, pattern_index, input) or
                   __rec__(string_index + 1, pattern_index + 1, input);
        }
        // exclude this
        answer = answer or __rec__(string_index, pattern_index + 1, input);
      }
    }  // non-repeatable pattern
    else {
      if (char_type[pattern_index] == '.' or
          input[string_index] == char_type[pattern_index]) {
        answer = __rec__(string_index + 1, pattern_index + 1, input);
      } else {
        answer = false;
      }
    }

    memo[string_index][pattern_index] = answer;
    return answer;
  }

  inline void parsePattern(const string& pattern) {
    for (char c : pattern) {
      if (c == '*') {
        *is_repeat.rbegin() = true;
      } else {
        char_type.push_back(c);
        is_repeat.push_back(false);
      }
    }
  }

  bool isMatch(string input, string pattern) {
    parsePattern(pattern);
    memo = vector<vector<int>>(input.size(), vector<int>(char_type.size(), -2));

    return __rec__(0, 0, input);
  }
};

int main() {
  return 0;
}
