class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int answer = 0;
    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[i].size(); j++)
        // check left
        if (j - 1 >= 0 and board[i][j - 1] != '.')
          continue;
        else if (i - 1 >= 0 and board[i - 1][j] != '.')
          continue;
        else if (board[i][j] != '.')
          answer += 1;
    return answer;
  }
};