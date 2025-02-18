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

  void walk(int si, int sj, bool rev, vint& answer, const vvint& values) {
    if (not rev) {
      for (int i = si, j = sj; i < values.size() and j > -1; i++, j--) {
        answer.push_back(values[i][j]);
      }
    } else {
      const int m = values.size();
      const int n = values[0].size();
      int maxsteps = min(m - si - 1, sj);
      int usi = si + maxsteps;
      int usj = sj - maxsteps;
      for (int i = usi, j = usj; i > -1 and j < n; i--, j++) {
        answer.push_back(values[i][j]);
      }
    }
  }

  vector<int> findDiagonalOrder(vector<vector<int>>& values) {
    bool reverse = true;
    vint answer;

    const int m = values.size();
    const int n = values[0].size();

    for (int j = 0; j < n; j++) {
      walk(0, j, reverse, answer, values);
      reverse = not reverse;
    }

    for (int i = 1; i < m; i++) {
      walk(i, n - 1, reverse, answer, values);
      reverse = not reverse;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
