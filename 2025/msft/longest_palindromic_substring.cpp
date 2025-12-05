class Solution {
 public:
  vector<vector<int>> memo;

  bool is_valid(int a, int b, const string& input) {
    if (a == b)
      return true;

    if (a > b)
      return true;

    if (memo[a][b] != INT_MIN)
      return memo[a][b] == 1;

    bool answer = false;
    if (input[a] == input[b]) {
      answer = is_valid(a + 1, b - 1, input);
    }

    memo[a][b] = answer;
    return answer;
  }

  string longestPalindrome(string input) {
    memo =
        vector<vector<int>>(input.size(), vector<int>(input.size(), INT_MIN));

    int answer = 0;
    string temp;
    for (int i = 0; i < input.size(); i++) {
      for (int j = i; j < input.size(); j++) {
        if (is_valid(i, j, input)) {
          int current = j - i + 1;
          if (current > answer) {
            answer = current;
            temp = input.substr(i, current);
          }
        }
      }
    }
    return temp;
  }
};
