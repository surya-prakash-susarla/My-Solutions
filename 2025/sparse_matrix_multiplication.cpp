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
  vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    const int n = a.size();
    const int k = a[0].size();
    const int m = b[0].size();

    vvint answer(n, vint(m));

    unordered_map<int, unordered_set<int>> b_values;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < m; j++) {
        if (b[i][j] != 0)
          b_values[j].insert(i);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int l = 0; l < k; l++) {
          if (a[i][l] != 0) {
            if (b_values.contains(j) and b_values[j].contains(l)) {
              answer[i][j] += a[i][l] * b[l][j];
            }
          }
        }
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
