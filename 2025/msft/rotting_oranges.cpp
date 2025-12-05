class Solution {
 public:
  int orangesRotting(vector<vector<int>>& input) {
    auto generate_locations = [&](const int i, const int j,
                                  queue<pair<int, int>>& locations) -> void {
      if (i - 1 > -1 and input[i - 1][j] == 1) {
        input[i - 1][j] = 2;
        locations.push({i - 1, j});
      }
      if (j - 1 > -1 and input[i][j - 1] == 1) {
        input[i][j - 1] = 2;
        locations.push({i, j - 1});
      }
      if (i + 1 < input.size() and input[i + 1][j] == 1) {
        input[i + 1][j] = 2;
        locations.push({i + 1, j});
      }
      if (j + 1 < input[0].size() and input[i][j + 1] == 1) {
        input[i][j + 1] = 2;
        locations.push({i, j + 1});
      }
    };

    int fresh_count = 0;

    queue<pair<int, int>> current;
    for (int i = 0; i < input.size(); i++)
      for (int j = 0; j < input[0].size(); j++) {
        if (input[i][j] == 1) {
          fresh_count++;
        } else if (input[i][j] == 2) {
          current.push({i, j});
        }
      }

    if (current.size())
      fresh_count += current.size();

    int answer = -1;
    while (not current.empty()) {
      queue<pair<int, int>> next;
      answer++;
      while (not current.empty()) {
        pair<int, int> temp = current.front();
        fresh_count--;
        current.pop();
        generate_locations(temp.first, temp.second, next);
      }
      swap(current, next);
    }

    if (fresh_count == 0) {
      if (answer != -1)
        return answer;
      else
        return 0;
    } else {
      return -1;
    }
  }
};
