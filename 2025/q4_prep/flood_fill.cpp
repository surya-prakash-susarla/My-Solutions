class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& input,
                                int sr,
                                int sc,
                                int color) {
    queue<pair<int, int>> values;
    values.push({sr, sc});

    auto generate = [&](const int i, const int j) {
      values.push({i + 1, j});
      values.push({i, j + 1});
      values.push({i - 1, j});
      values.push({i, j - 1});
    };

    int initial_color = input[sr][sc];

    while (not values.empty()) {
      const pair<int, int> current = values.front();
      values.pop();

      if (current.first < 0 or current.first >= input.size() or
          current.second < 0 or current.second >= input[0].size())
        continue;

      if (input[current.first][current.second] == color or
          input[current.first][current.second] != initial_color)
        continue;

      input[current.first][current.second] = color;
      generate(current.first, current.second);
    }

    return input;
  }
};
