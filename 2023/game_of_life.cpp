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

  inline int get_live_count(int i, int j, const vvint& values) {
    int answer = 0;
#define update(x, y)                                                       \
  if (x > -1 and y > -1 and x < values.size() and y < values[0].size() and \
      values[x][y] == 1)                                                   \
  answer++

    update(i - 1, j - 1);
    update(i - 1, j);
    update(i - 1, j + 1);
    update(i, j - 1);
    update(i, j + 1);
    update(i + 1, j - 1);
    update(i + 1, j);
    update(i + 1, j + 1);

    return answer;
  }

  void gameOfLife(vector<vector<int>>& input) {
    vector<vector<int>> update;
    update = input;
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        int lc = get_live_count(i, j, input);
        if (input[i][j] == 1) {
          if (lc < 2 or lc > 3)
            update[i][j] = 0;
          else
            update[i][j] = 1;
        } else {
          if (lc == 3)
            update[i][j] = 1;
        }
      }
    }
    input = update;
    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
