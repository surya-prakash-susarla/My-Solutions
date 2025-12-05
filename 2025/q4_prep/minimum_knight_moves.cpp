class Solution {
 public:
  int minKnightMoves(int x, int y) {
    queue<pair<int, int>> values;

    auto generate = [&](const int i, const int j,
                        queue<pair<int, int>>& values) -> void {
      values.push({i + 2, j + 1});
      values.push({i + 2, j - 1});
      values.push({i - 2, j + 1});
      values.push({i - 2, j - 1});
      values.push({i + 1, j + 2});
      values.push({i - 1, j + 2});
      values.push({i + 1, j - 2});
      values.push({i - 1, j - 2});
    };

    values.push({0, 0});

    unordered_map<int, unordered_set<int>> covered;

    int answer = 0;

    while (not values.empty()) {
      answer++;

      queue<pair<int, int>> next;
      while (not values.empty()) {
        pair<int, int> temp = values.front();
        values.pop();

        if (covered[temp.first].contains(temp.second))
          continue;
        covered[temp.first].insert(temp.second);

        if (temp.first == x and temp.second == y)
          return answer - 1;

        generate(temp.first, temp.second, next);
      }

      swap(values, next);
    }

    return INT_MAX;
  }
};
