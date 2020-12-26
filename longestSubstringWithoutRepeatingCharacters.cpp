class Solution {
 public:
  string remain(string input, char c) {
    for (int i = input.size() - 1; i > -1; i--)
      if (input[i] == c)
        return input.substr(i + 1);
    return input;
  }

  int lengthOfLongestSubstring(string s) {
    int max_value = 0;
    string current_value("");
    for (char c : s) {
      max_value = max(max_value, (int)current_value.size());
      string rem = remain(current_value, c);
      current_value = rem + c;
    }
    max_value = max(max_value, (int)current_value.size());
    return max_value;
  }
};