class Solution {
 public:
  void dfs(int x, int y, vector<vector<int>>& grid) {
    if (x < 0 or y < 0 or x == grid.size() or y == grid.size() or
        grid[x][y] == 1)
      return;
    // cout << x << " " << y << endl;
    grid[x][y] = 1;
    dfs(x - 1, y, grid), dfs(x + 1, y, grid), dfs(x, y - 1, grid),
        dfs(x, y + 1, grid);
    return;
  }

  int regionsBySlashes(vector<string>& grid) {
    vector<vector<int>> input(grid.size() * 3, vector<int>(grid.size() * 3, 0));
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid.size(); j++)
        if (grid[i][j] == '/')
          input[i * 3][j * 3 + 2] = input[i * 3 + 1][j * 3 + 1] =
              input[i * 3 + 2][j * 3] = 1;
        else if (grid[i][j] == '\\')
          input[i * 3][j * 3] = input[i * 3 + 1][j * 3 + 1] =
              input[i * 3 + 2][j * 3 + 2] = 1;
    int answer = 0;
    for (int i = 0; i < input.size(); i++)
      for (int j = 0; j < input.size(); j++)
        if (input[i][j] == 0) {
          dfs(i, j, input);
          // cout << "incrementing count " << i << " " << j << endl;
          answer++;
        }
    return answer;
  }
};