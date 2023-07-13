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
  int uniquePaths(int m, int n) {
    vector<vector<int>> values(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      values[m - 1][i] = 1;
    for (int i = 0; i < m; i++)
      values[i][n - 1] = 1;

    for (int i = m - 2; i > -1; i--) {
      for (int j = n - 2; j > -1; j--) {
        values[i][j] = values[i + 1][j] + values[i][j + 1];
      }
    }

    return values[0][0];
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
