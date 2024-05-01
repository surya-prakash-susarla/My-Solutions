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
  map<int, double> memo;

  double __rec__(double x, int p) {
    if (p == 1)
      return x;

    auto it = memo.find(p);
    if (it != memo.end())
      return it->second;

    int left = p / 2;
    int right = p - left;
    double answer = __rec__(x, left) * __rec__(x, right);
    memo[p] = answer;
    return answer;
  }

  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    if (x == 1)
      return 1;

    bool neg = false;
    bool inc = false;
    if (n < 0) {
      neg = true;
      if (n == INT_MIN) {
        inc = true;
        n = INT_MAX;
      } else {
        n = 0 - n;
      }
    }

    double answer = __rec__(x, n);
    if (inc)
      answer *= x;

    return neg ? 1 / answer : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
