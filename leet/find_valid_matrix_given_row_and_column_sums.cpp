#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  using vint = vector<int>;
  using vvint = vector<vint>;
  using pint = pair<int, int>;

  void __calc__(int x, int y, vvint& answer, vint& xr, vint& yr) {
    const size_t rsize = answer.size();
    const size_t csize = rsize > 0 ? answer[0].size() : 0;

    if (x >= rsize or y >= csize)
      return;

    answer[x][y] = min(xr[x], yr[y]);

    xr[x] -= answer[x][y];
    yr[y] -= answer[x][y];

    if (xr[x] == 0) {
      for (int i = y + 1; i < csize; i++)
        answer[x][i] = 0;

      for (int i = x + 1; i < rsize; i++) {
        answer[i][y] = min(xr[i], yr[y]);
        xr[i] -= answer[i][y];
        yr[y] -= answer[i][y];
      }
    } else if (yr[y] == 0) {
      for (int i = x + 1; i < rsize; i++)
        answer[i][y] = 0;

      for (int i = y + 1; i < csize; i++) {
        answer[x][i] = min(xr[x], yr[i]);
        xr[x] -= answer[x][i];
        yr[i] -= answer[x][i];
      }
    }

    __calc__(x + 1, y + 1, answer, xr, yr);
  }

  vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
    vvint answer(r.size(), vint(c.size(), 0));
    __calc__(0, 0, answer, r, c);
    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
