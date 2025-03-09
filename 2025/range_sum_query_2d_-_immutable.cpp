#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class NumMatrix {
 public:
  vector<vector<int>> values;
  vector<vector<int>> input;
  int m;
  int n;
  NumMatrix(vector<vector<int>>& input) {
    values = vector<vector<int>>(input.size(), vector<int>(input[0].size()));

    m = input.size();
    n = input[0].size();

    for (int i = 0; i < m; i++) {
      values[i][0] = input[i][0];
      for (int j = 1; j < n; j++)
        values[i][j] = input[i][j] + values[i][j - 1];
    }

    for (int j = 0; j < n; j++) {
      for (int i = 1; i < m; i++) {
        values[i][j] += values[i - 1][j];
      }
    }

    this->input = input;
  }

  int get(int i, int j) {
    if (i < 0 or j < 0 or i >= m or j >= n) {
      return 0;
    }
    return values[i][j];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    if (row1 == row2 and col1 == col2) {
      return input[row1][col1];
    }
    return (get(row2, col2) - get(row2, col1 - 1)) -
           (get(row1 - 1, col2) - get(row1 - 1, col1 - 1));
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
