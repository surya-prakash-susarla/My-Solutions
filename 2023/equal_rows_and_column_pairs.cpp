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
  int equalPairs(vector<vector<int>>& values) {
    typedef vector<int> vint;

    map<vint, int> rows;
    map<vint, int> cols;

    const int n = values.size();
    const int m = values[0].size();

    for (int i = 0; i < n; i++) {
      vint current;
      for (int j = 0; j < m; j++)
        current.push_back(values[i][j]);
      rows[current]++;
    }

    for (int j = 0; j < m; j++) {
      vint current;
      for (int i = 0; i < n; i++)
        current.push_back(values[i][j]);
      cols[current]++;
    }

    int answer = 0;

    for (const pair<vint, int>& row : rows) {
      answer += (row.second * cols[row.first]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
