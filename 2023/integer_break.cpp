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
  map<int, int> memo;

  int __rec__(int n, bool should_break = false) {
    if (n == 1)
      return 1;

    if (memo[n] != 0)
      return memo[n];

    int answer = INT_MIN;
    for (int i = 1; i <= n / 2; i++) {
      int current = __rec__(i) * __rec__(n - i);
      answer = max(answer, current);
    }

    if (not should_break)
      answer = max(answer, n);

    memo[n] = answer;
    return answer;
  }

  int integerBreak(int n) { return __rec__(n, true); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
