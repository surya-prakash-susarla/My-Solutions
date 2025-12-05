class Solution {
 public:
  string longestCommonPrefix(vector<string>& input) {
    int answer = input[0].size();

    for (int i = 1; i < input.size(); i++) {
      for (int j = 0; j < answer and j < input[i].size(); j++) {
        if (input[0][j] != input[i][j]) {
          answer = j;
          break;
        }
      }
      answer = min(answer, (int)input[i].size());
    }

    return input[0].substr(0, answer);
  }
};
