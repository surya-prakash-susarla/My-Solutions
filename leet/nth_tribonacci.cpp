#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  int tribonacci(int n) {
    vector<int> values = {0, 1, 1};
    if (n < 3)
      return values[n];

    int csum = 2;
    for (int i = 3; i < n; i++) {
      swap(values[0], values[1]);
      swap(values[1], values[2]);
      values[2] = csum;
      csum = values[0] + values[1] + values[2];
    }

    return csum;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
