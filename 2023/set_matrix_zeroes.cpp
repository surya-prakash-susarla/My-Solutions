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
  typedef set<int> sint;

  int n;
  int m;

  void make_z(vvint& values, sint rows, sint cols) {
    for (int i : rows) {
      for (int j = 0; j < m; j++)
        values[i][j] = 0;
    }

    for (int i : cols) {
      for (int j = 0; j < n; j++)
        values[j][i] = 0;
    }
  }

  void setZeroes(vector<vector<int>>& input) {
    n = input.size();
    m = input[0].size();

    sint rows;
    sint cols;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (input[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }

    make_z(input, rows, cols);

    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
