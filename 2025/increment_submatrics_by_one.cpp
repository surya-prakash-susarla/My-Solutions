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

  void update(int r1, int c1, int r2, int c2, vvint& ref) {
    for (int i = r1; i <= r2; i++)
      for (int j = c1; j <= c2; j++)
        ref[i][j]++;
  }

  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& input) {
    vvint values(n, vint(n, 0));
    for (vint& i : input) {
      update(i[0], i[1], i[2], i[3], values);
    }
    return values;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
