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
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& values) {
    const int m = values.size();
    const int n = values[0].size();

    vector<int> row_ones;
    vector<int> col_ones;

    // find ones in rows.
    for (int i = 0; i < m; i++) {
      int temp = 0;
      for (int j = 0; j < n; j++)
        if (values[i][j] == 1)
          temp++;
      row_ones.push_back(temp);
    }

    // find ones in cols.
    for (int j = 0; j < n; j++) {
      int temp = 0;
      for (int i = 0; i < m; i++)
        if (values[i][j] == 1)
          temp++;
      col_ones.push_back(temp);
    }

    vector<vector<int>> answer(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        answer[i][j] = (2 * row_ones[i] - m) + (2 * col_ones[j] - n);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
