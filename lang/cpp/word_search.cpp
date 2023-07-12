class Solution {
 public:
  int rows, cols;

  bool find_value(vector<vector<char>> board,
                  string word,
                  int wp,
                  int i,
                  int j) {
    if (wp == word.size())
      return true;
    if (i < 0 or j < 0 or i >= rows or j >= cols)
      return false;
    if (board[i][j] == '0')
      return false;  // visited node
    if (board[i][j] != word[wp])
      return false;
    board[i][j] = '0';
    return (find_value(board, word, wp + 1, i + 1, j) or
            find_value(board, word, wp + 1, i - 1, j) or
            find_value(board, word, wp + 1, i, j + 1) or
            find_value(board, word, wp + 1, i, j - 1));
  }

  bool exist(vector<vector<char>>& board, string word) {
    rows = board.size();
    if (rows > 0)
      cols = board[0].size();

    if (rows == 0)
      if (word.size() == 0)
        return true;
      else
        return false;

    if (word.size() == 0)
      return true;

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++) {
        if (board[i][j] == word[0] and find_value(board, word, 0, i, j))
          return true;
      }
    return false;
  }
};