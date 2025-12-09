class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& input) {
    const int m = input.size();
    const int n = input[0].size();

    queue<pair<int, int>> current;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (input[i][j] == 0)
          current.push({i, j});
      }
    }

    auto update_if_valid = [&](int i, int j, int initial_value,
                               queue<pair<int, int>>& ref) -> void {
      if (i < 0 or j < 0 or i >= m or j >= n or input[i][j] == -1)
        return;

      int current = initial_value + 1;
      if (current < input[i][j]) {
        input[i][j] = current;
        ref.push({i, j});
      }
    };

    while (not current.empty()) {
      pair<int, int> temp = current.front();
      int i = temp.first;
      int j = temp.second;
      current.pop();

      update_if_valid(i - 1, j, input[i][j], current);
      update_if_valid(i, j - 1, input[i][j], current);
      update_if_valid(i + 1, j, input[i][j], current);
      update_if_valid(i, j + 1, input[i][j], current);
    }

    return;
  }
};
