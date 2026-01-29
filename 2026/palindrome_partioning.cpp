class Solution {
 public:
  bool is_palindrome(int start, int end, const string& s) {
    while (start <= end) {
      if (s[start] != s[end])
        return false;
      start++;
      end--;
    }
    return true;
  }

  unordered_map<int, vector<vector<string>>> memo;

  vector<vector<string>> solve(int start, const string& s) {
    if (start >= s.size())
      return {};

    if (memo.contains(start))
      return memo[start];

    vector<vector<string>> answer;
    for (int end = start; end < s.size(); end++) {
      if (is_palindrome(start, end, s)) {
        string current = s.substr(start, end - start + 1);
        vector<vector<string>> next = solve(end + 1, s);
        for (auto i : next) {
          vector<string> temp = {current};
          temp.insert(temp.end(), i.begin(), i.end());
          answer.push_back(temp);
        }
        if (next.empty())
          answer.push_back({current});
      }
    }

    memo[start] = answer;
    return answer;
  }

  vector<vector<string>> partition(string s) { return solve(0, s); }
};
