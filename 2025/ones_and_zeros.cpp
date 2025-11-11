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
  typedef pair<int, int> pint;
  typedef vector<pint> vpint;

  vpint input;

  vector<vector<vector<int>>> memo;

  int __rec__(int i, int m, int n) {
    if (i == input.size()) {
      return 0;
    }

    if (memo[i][m][n] != -1)
      return memo[i][m][n];

    int incl = 0;
    if (input[i].first <= m and input[i].second <= n) {
      incl = 1 + __rec__(i + 1, m - input[i].first, n - input[i].second);
    }
    int excl = __rec__(i + 1, m, n);

    int answer = max(incl, excl);
    memo[i][m][n] = answer;
    return answer;
  }

  int findMaxForm(vector<string>& raw_input, int m, int n) {
    memo = vector<vector<vector<int>>>(
        raw_input.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    input = vpint(raw_input.size(), make_pair(0, 0));
    for (int i = 0; i < raw_input.size(); i++) {
      for (char c : raw_input[i])
        if (c == '0') {
          input[i].first++;
        } else {
          input[i].second++;
        }
    }
    sort(input.begin(), input.end(), [](const pint& a, const pint& b) {
      int t1 = a.first + a.second;
      int t2 = b.first + b.second;
      return t1 < t2;
    });

    return __rec__(0, m, n);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
