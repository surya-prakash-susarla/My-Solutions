class Solution {
 public:
  vector<vector<int>> memo;

  int __rec__(int start, int end, const string& s) {
    if (start > end)
      return 0;
    if (start == end)
      return 1;

    if (memo[start][end] != -1)
      return memo[start][end];

    vector<bool> used(26, false);

    int answer = 0;
    for (int i = start; i <= end; i++) {
      if (used[s[i] - 'a'])
        continue;

      used[s[i] - 'a'] = true;
      for (int j = end; j >= i; j--) {
        if (i == j) {
          answer = max(answer, 1);
          continue;
        }
        if (s[i] == s[j]) {
          int current = 2 + __rec__(i + 1, j - 1, s);
          answer = max(answer, current);
          break;
        }
      }
    }

    memo[start][end] = answer;
    return answer;
  }

  int longestPalindromeSubseq(string s) {
    memo = vector<vector<int>>(s.size() + 1, vector<int>(s.size() + 1, -1));
    return __rec__(0, s.size() - 1, s);
  }
};
