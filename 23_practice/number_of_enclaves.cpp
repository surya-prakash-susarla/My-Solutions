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
  typedef pair<int, int> pint;

  static constexpr pint nan = make_pair(-1, -1);

  inline pint make(int x, int y) { return make_pair(x, y); }

  inline pair<int, bool> make(int x, bool y) { return make_pair(x, y); }

  void update(pair<int, bool> a, pair<int, bool>& b) {
    b.first += a.first;
    b.second |= a.second;
  }

  pair<int, bool> __rec__(int x, int y, vvint& values) {
    if (x < 0 or y < 0 or x >= values.size() or y >= values[0].size()) {
      return make(0, true);
    }
    if (values[x][y] == 0)
      return make(0, false);

    values[x][y] = 0;
    pair<int, bool> answer = make(1, false);

    update(__rec__(x - 1, y, values), answer);
    update(__rec__(x + 1, y, values), answer);
    update(__rec__(x, y - 1, values), answer);
    update(__rec__(x, y + 1, values), answer);

    return answer;
  }

  pint find(const vvint& values) {
    int m = values.size();
    int n = values[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (values[i][j] == 1)
          return make(i, j);
    return nan;
  }

  int numEnclaves(vector<vector<int>>& grid) {
    pint point = find(grid);
    int answer = 0;
    while (point != nan) {
      pair<int, bool> result = __rec__(point.first, point.second, grid);
      if (not result.second)
        answer += result.first;
      point = find(grid);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
