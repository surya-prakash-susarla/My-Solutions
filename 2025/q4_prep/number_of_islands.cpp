class Solution {
 public:
  void fill(int i, int j, vector<vector<char>>& input) {
    if (i < 0 or j < 0 or i == input.size() or j == input[0].size())
      return;

    if (input[i][j] == '1') {
      input[i][j] = '0';
      fill(i - 1, j, input);
      fill(i, j - 1, input);
      fill(i, j + 1, input);
      fill(i + 1, j, input);
    }

    return;
  }

  int numIslands(vector<vector<char>>& input) {
    int answer = 0;
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        if (input[i][j] == '1') {
          answer++;
          fill(i, j, input);
        }
      }
    }
    return answer;
  }
};
