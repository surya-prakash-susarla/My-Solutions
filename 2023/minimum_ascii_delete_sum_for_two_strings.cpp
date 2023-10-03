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
  vector<vector<int>> memo;

  int __rec__(int ai, int bi, const string& a, const string& b) {
    if (ai == a.size()) {
      int answer = 0;
      for (int i = bi; i < b.size(); i++)
        answer += int(b[i]);
      return answer;
    }
    if (bi == b.size()) {
      int answer = 0;
      for (int i = ai; i < a.size(); i++)
        answer += int(a[i]);
      return answer;
    }

    if (memo[ai][bi] != -1)
      return memo[ai][bi];

    int incl = INT_MAX;
    if (a[ai] == b[bi]) {
      incl = __rec__(ai + 1, bi + 1, a, b);
    }
    int a_drop = INT_MAX;
    if (ai < a.size()) {
      a_drop = int(a[ai]) + __rec__(ai + 1, bi, a, b);
    }
    int b_drop = INT_MAX;
    if (bi < b.size()) {
      b_drop = int(b[bi]) + __rec__(ai, bi + 1, a, b);
    }

    memo[ai][bi] = min({incl, a_drop, b_drop});
    return memo[ai][bi];
  }

  int minimumDeleteSum(string a, string b) {
    memo = vector<vector<int>>(a.size(), vector<int>(b.size(), -1));
    return __rec__(0, 0, a, b);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
