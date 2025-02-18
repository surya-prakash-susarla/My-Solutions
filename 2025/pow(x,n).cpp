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
  unordered_map<unsigned int, double> memo;

  double calc(double x, long long int n) {
    auto it = memo.find(n);
    if (it != memo.end())
      return it->second;

    // cout << "calcing : " << x << " , n : " << n << endl;

    if (n == 1)
      return x;

    memo[n] = calc(x, n / 2) * calc(x, (n % 2 ? n / 2 + 1 : n / 2));

    return memo[n];
  }

  double myPow(double x, int n) {
    if (x == 0)
      return 0;
    if (n == 0 or x == 1)
      return 1;

    if (n < 0) {
      return (double)1 / (calc(x, (long long int)(0 - (long long int)n)));
    } else {
      return calc(x, n);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
