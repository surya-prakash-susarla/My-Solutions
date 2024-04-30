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
  pair<int, int> get_next(int i,
                          int j,
                          int direction,
                          const int r1,
                          const int c1,
                          const int r2,
                          const int c2) {
    pair<int, int> return_value;
    switch (direction) {
      case 0:
        return_value = {r1 + (j - c1), c2};
        break;
      case 1:
        return_value = {r2, c2 - (i - r1)};
        break;
      case 2:
        return_value = {r2 - (c2 - j), c1};
        break;
      case 3:
        return_value = {r1, c1 + (r2 - i)};
        break;
    }
    return return_value;
  }

  void rotate(vector<vector<int>>& values) {
    int r1 = 0;
    int r2 = values.size() - 1;
    int c1 = 0;
    int c2 = values[0].size() - 1;

    while (r1 <= r2) {
      for (int j = c1; j < c2; j++) {
        int current = values[r1][j];
        int temp = values[r1][j];
        // right
        pair<int, int> next = get_next(r1, j, 0, r1, c1, r2, c2);
        temp = values[next.first][next.second];
        values[next.first][next.second] = current;
        current = temp;

        // down
        next = get_next(next.first, next.second, 1, r1, c1, r2, c2);
        temp = values[next.first][next.second];
        values[next.first][next.second] = current;
        current = temp;

        // left
        next = get_next(next.first, next.second, 2, r1, c1, r2, c2);
        temp = values[next.first][next.second];
        values[next.first][next.second] = current;
        current = temp;

        // top
        next = get_next(next.first, next.second, 3, r1, c1, r2, c2);
        temp = values[next.first][next.second];
        values[next.first][next.second] = current;
        current = temp;
      }
      r1++;
      r2--;
      c1++;
      c2--;
    }
    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
