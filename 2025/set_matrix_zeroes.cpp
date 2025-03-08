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
  void setZeroes(vector<vector<int>>& input) {
    set<int> rows;
    set<int> cols;
    int m = input.size();
    int n = input[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (input[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }

    for (int i : rows) {
      for (int j = 0; j < n; j++)
        input[i][j] = 0;
    }

    for (int j : cols) {
      for (int i = 0; i < m; i++)
        input[i][j] = 0;
    }

    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
