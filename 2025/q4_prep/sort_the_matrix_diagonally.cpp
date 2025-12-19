class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& input) {
    const int n = input.size();
    const int m = input[0].size();

    for (int k = 0; k < n; k++) {
      vector<int> temp;
      for (int i = k, j = 0; i < n and j < m; i++, j++) {
        temp.push_back(input[i][j]);
      }

      sort(temp.begin(), temp.end());

      int index = 0;
      for (int i = k, j = 0; i < n and j < m; i++, j++) {
        input[i][j] = temp[index++];
      }
    }

    for (int k = 1; k < m; k++) {
      vector<int> temp;
      for (int i = 0, j = k; i < n and j < m; i++, j++) {
        temp.push_back(input[i][j]);
      }

      sort(temp.begin(), temp.end());

      int index = 0;
      for (int i = 0, j = k; i < n and j < m; i++, j++) {
        input[i][j] = temp[index++];
      }
    }

    return input;
  }
};
