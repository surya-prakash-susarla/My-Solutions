class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& input) {
    vector<int> answer;

    bool top = true;

    int i = 0;
    int j = 0;

    auto move_top = [&]() {
      while (true) {
        answer.push_back(input[i][j]);
        if (i - 1 > -1 and j + 1 < input[0].size()) {
          i -= 1;
          j += 1;
        } else {
          return;
        }
      }
    };

    auto move_down = [&]() {
      while (true) {
        answer.push_back(input[i][j]);
        if (i + 1 < input.size() and j - 1 > -1) {
          i += 1;
          j -= 1;
        } else {
          return;
        }
      }
    };

    auto nxt = [&]() {
      if (top) {
        if (j + 1 < input[0].size()) {
          j++;
        } else {
          i++;
        }
      } else {
        if (i + 1 < input.size()) {
          i++;
        } else {
          j++;
        }
      }
    };

    while (true) {
      if (top) {
        move_top();
      } else {
        move_down();
      }
      nxt();
      top = not top;

      if (i == input.size() or j == input[0].size())
        break;
    }

    return answer;
  }
};
