class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& input) {
    int rb = 0;
    int cb = 0;
    int r = input.size();
    int c = input[0].size();

    vector<int> answer;

    int i = 0;
    int j = 0;

    auto move_right = [&]() {
      bool moved = false;
      while (j < c) {
        cout << "moving right : " << i << " , " << j << endl;
        answer.push_back(input[i][j++]);
        moved = true;
      }
      j--;
      return moved;
    };
    auto move_down = [&]() {
      bool moved = false;
      i++;
      while (i < r) {
        cout << "moving down : " << i << " , " << j << endl;
        answer.push_back(input[i++][j]);
        moved = true;
      }
      i--;
      return moved;
    };
    auto move_left = [&]() {
      bool moved = false;
      j--;
      while (j >= cb) {
        cout << "moving left : " << i << " , " << j << endl;
        answer.push_back(input[i][j--]);
        moved = true;
      }
      j++;
      return moved;
    };
    auto move_top = [&]() {
      bool moved = false;
      i--;
      while (i > rb) {
        cout << "moving top : " << i << " , " << j << endl;
        answer.push_back(input[i--][j]);
        moved = true;
      }
      i++;
      return moved;
    };

    while (true) {
      if (move_right()) {
        if (move_down()) {
          if (move_left()) {
            move_top();
          }
        }
      }

      rb++;
      cb++;
      r--;
      c--;

      j++;

      if (rb >= r or cb >= c)
        break;
    }

    return answer;
  }
};
