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
  int uniquePathsWithObstacles(vector<vector<int>>& input) {
    int n = input.size();
    int m = input[0].size();

    typedef unsigned long long ull;
    vector<vector<ull>> memo(n, vector<ull>(m));

    for (int i = n - 1; i > -1; i--) {
      for (int j = m - 1; j > -1; j--) {
        ull right = j + 1 < m ? memo[i][j + 1] : 0;
        ull down = i + 1 < n ? memo[i + 1][j] : 0;

        memo[i][j] = input[i][j] == 1 ? 0 : right + down;

        if (i == n - 1 and j == m - 1)
          memo[i][j] = input[i][j] == 0 ? 1 : 0;
      }
    }

    return memo[0][0];
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
