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
  int m;
  int n;
  typedef vector<int> vint;
  typedef vector<vint> vvint;
  typedef vector<bool> vbool;
  typedef vector<vbool> vvbool;

  int answer = 0;
  vvint target;

  inline void flip(vvint& values, int i, int j) {
    values[i][j] = not values[i][j];
    if (i - 1 > -1)
      values[i - 1][j] = not values[i - 1][j];
    if (j - 1 > -1)
      values[i][j - 1] = not values[i][j - 1];
    if (i + 1 < m)
      values[i + 1][j] = not values[i + 1][j];
    if (j + 1 < n)
      values[i][j + 1] = not values[i][j + 1];
  }

  int __calc__(vvint values) {
    int dist = 0;
    queue<pair<vvint, vvbool>> pending;
    pending.push({values, vvbool(m, vbool(n, false))});
    set<vvint> memo;

    while (not pending.empty()) {
      queue<pair<vvint, vvbool>> next;
      while (not pending.empty()) {
        pair<vvint, vvbool> current = pending.front();
        pending.pop();
        if (memo.contains(current.first)) {
          continue;
        } else {
          memo.insert(current.first);
        }
        if (current.first == target) {
          return dist;
        } else {
          for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
              if (not current.second[i][j]) {
                vvint temp = current.first;
                vvbool temp2 = current.second;
                flip(temp, i, j);
                temp2[i][j] = true;
                next.push(move(make_pair(temp, temp2)));
              }
            }
          }
        }
      }
      swap(pending, next);
      dist++;
    }
    return -1;
  }

  int minFlips(vector<vector<int>>& input) {
    m = input.size();
    n = input[0].size();

    target = vvint(m, vint(n));

    return __calc__(input);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
