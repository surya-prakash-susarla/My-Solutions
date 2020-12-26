class Solution {
 public:
  bool find(int index, string str, vector<string> wl, vector<int>& dp) {
    if (index >= str.size())
      return true;
    if (dp[index] != 2)
      return bool(dp[index]);
    dp[index] = 0;
    for (int i = 0; i < wl.size(); i++)
      if (wl[i][0] == str[index])
        if (wl[i] == str.substr(index, wl[i].size()))
          if (find(index + wl[i].size(), str, wl, dp)) {
            dp[index] = 1;
            return true;
          }
    return false;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    vector<int> dp(s.size(), 2);
    return find(0, s, wordDict, dp);
  }
};