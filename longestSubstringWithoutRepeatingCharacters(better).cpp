class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0)
      return 0;
    int prev_value = 1;
    int max_value = 1;
    for (int i = s.size() - 2; i > -1; i--) {
      int cnt = 0;
      for (int j = i + 1; j <= i + prev_value && s[j] != s[i]; j++, cnt++) {
      }
      prev_value = cnt + 1;
      max_value = max(max_value, prev_value);
    }
    return max_value;
  }
};