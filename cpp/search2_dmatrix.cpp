class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int max_row = -1, max_col = -1;

    if (matrix.size() == 0 or matrix[0].size() == 0)
      return false;

    for (int i = 0; i < matrix.size(); i++)
      if (matrix[i][0] <= target)
        max_row = i;
      else
        break;

    if (max_row == -1)
      return false;

    for (int i = 0; i < matrix[0].size(); i++)
      if (matrix[0][i] <= target)
        max_col = i;
      else
        break;

    if (max_col == -1)
      return false;

    for (int i = max_row; i > -1; i--)
      for (int j = max_col; j > -1; j--)
        if (matrix[i][j] == target)
          return true;
        else if (matrix[i][j] < target)
          continue;

    return false;
  }
};