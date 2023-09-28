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
  int climbStairs(int n) {
    if (n == 1)
      return 1;

    int pp = 1;
    int p = 1;

    for (int i = 2; i <= n; i++) {
      int c = p + pp;
      pp = p;
      p = c;
    }

    return p;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
