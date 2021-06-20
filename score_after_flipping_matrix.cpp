typedef long long int llint;

class Solution {
 public:
  void flipRow(int row, vector<vector<int>>& input) {
    for (int i = 0; i < input[row].size(); i++)
      input[row][i] = (input[row][i] + 1) % 2;
  }

  void flipCol(int col, vector<vector<int>>& input) {
    for (int i = 0; i < input.size(); i++)
      input[i][col] = (input[i][col] + 1) % 2;
  }

  llint matrixScore(vector<vector<int>>& input) {
    // first row change to all zero or one
    int zeroes = 0, ones = 0;
    for (int i = 0; i < input.size(); i++)
      if (input[i][0] == 1)
        ones++;
      else
        zeroes++;
    if (ones > zeroes) {
      for (int i = 0; i < input.size(); i++)
        if (input[i][0] == 0)
          flipRow(i, input);
    } else {
      // cout << " zeros greater than ones " << endl;
      for (int i = 0; i < input.size(); i++)
        if (input[i][0])
          flipRow(i, input);
      flipCol(0, input);
    }
    // individual col decision to flip it or not
    for (int i = 1; i < input[0].size(); i++) {
      int z = 0, one = 0;
      for (int j = 0; j < input.size(); j++)
        if (input[j][i] == 0)
          z += 1;
        else
          one += 1;
      if (z > one)
        flipCol(i, input);
    }
    // calculating final answer
    llint answer = 0;
    int cols = input[0].size() - 1;
    for (int i = 0; i < input.size(); i++) {
      llint current_number = 0;
      for (int j = 0; j < input[0].size(); j++)
        if (input[i][j])
          current_number += 1 << (cols - j);
      answer += current_number;
    }
    return answer;
  }
};