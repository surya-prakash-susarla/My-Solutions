#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rows, cols;

  // DEBUG METHOD
  void print(vector<vector<int>> values) {
    for (auto i : values)
      cout << i[0] << " " << i[1] << endl;
    return;
  }

  bool valid(int x, int y) {
    if (x >= 0 and x < this->rows and y >= 0 and y < this->cols)
      return true;
    return false;
  }

  vector<vector<int>> getRound(int x, int y, int length) {
    cout << "Starting at : " << x << " " << y << " length : " << length << endl;

    vector<vector<int>> answer;
    // top to bottom
    for (int i = 0; i < length; i++)
      if (valid(x + i, y)) {
        cout << "inserting in top to bottom " << x + i << " " << y << endl;
        answer.push_back(vector<int>{x + i, y});
      }

    x += (length - 1);
    y -= 1;
    // right to left
    for (int i = 0; i < length; i++)
      if (valid(x, y - i)) {
        cout << "inserting from right to left " << x << " " << y - i << endl;
        answer.push_back(vector<int>{x, y - i});
      }

    y -= (length - 1);
    x -= 1;
    // bottom to top
    for (int i = 0; i < length; i++)
      if (valid(x - i, y)) {
        cout << "inserting from bottom to top " << x - i << " " << y << endl;
        answer.push_back(vector<int>{x - i, y});
      }

    x -= (length - 1);
    y += 1;
    // left to right
    for (int i = 0; i < length; i++)
      if (valid(x, y + i)) {
        cout << "inserting from left to right " << x << " " << y + i << endl;
        answer.push_back(vector<int>{x, y + i});
      }

    // print ( answer );

    return answer;
  }

  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    this->rows = R;
    this->cols = C;

    vector<vector<int>> answer;
    if (valid(r0, c0))
      answer.push_back(vector<int>{r0, c0});

    int init_x = r0, init_y = c0 + 1, init_length = 0;

    while (answer.size() < this->rows * this->cols) {
      init_length += 2;

      // DEBUG
      cout << "while loop " << init_x << " " << init_y
           << " length : " << init_length << endl;

      vector<vector<int>> temp_answer = getRound(init_x, init_y, init_length);
      answer.insert(answer.end(), temp_answer.begin(), temp_answer.end());
      init_x -= 1, init_y += 1;

      // DEBUG
      cout << "length of answer : " << answer.size() << endl;
    }

    return answer;
  }
};

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  Solution temp;
  temp.print(temp.spiralMatrixIII(a, b, c, d));
  return 0;
}