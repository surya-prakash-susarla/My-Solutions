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
  vector<int> memo;

  int __calc__(int n) {
    if (memo[n] != -1)
      return memo[n];
    memo[n] = 0;
    if (n > 1)
      memo[n] += __calc__(n - 2);
    memo[n] += __calc__(n - 1);
    return memo[n];
  }

  int climbStairs(int n) {
    memo = vector<int>(n + 1, -1);
    memo[0] = 0;
    memo[1] = 1;
    if (n > 1)
      memo[2] = 2;
    int answer = __calc__(n);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
