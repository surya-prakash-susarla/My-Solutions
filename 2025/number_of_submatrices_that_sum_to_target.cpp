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

class Solution {
 public:
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  vvint input;
  vvint values;

  int __rec__(int i, int j, int x, int y) {
    if (i == x and j == y)
      return input[i][j];

    const int x1 = values[x][y];
    const int x2 = j - 1 > -1 ? values[x][j - 1] : 0;
    const int x3 = i - 1 > -1 ? values[i - 1][y] : 0;
    const int x4 = (i - 1 > -1 and j - 1 > -1) ? values[i - 1][j - 1] : 0;

    return x1 - x2 - x3 + x4;
  }

  vvint __calc__() {
    const int m = input.size();
    const int n = input[0].size();

    vvint values(m, vint(n));

    auto calc = [&](int i, int j) -> int {
      const int y = (i - 1 > -1 and j - 1 > -1) ? values[i - 1][j - 1] : 0;
      const int a = (j - 1 > -1) ? values[i][j - 1] : 0;
      const int b = (i - 1 > -1) ? values[i - 1][j] : 0;
      return input[i][j] + a + b - y;
    };

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        values[i][j] = calc(i, j);
      }
    }

    return values;
  }

  int numSubmatrixSumTarget(vector<vector<int>>& input, int target) {
    const int m = input.size();
    const int n = input[0].size();

    this->input = input;
    values = __calc__();

    int answer = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = i; k < m; k++) {
          for (int l = j; l < n; l++) {
            const int temp = __rec__(i, j, k, l);
            if (temp == target) {
              answer++;
            }
          }
        }
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
