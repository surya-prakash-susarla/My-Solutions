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
  int minOperations(int n) {
    typedef long long int llint;
    llint tsum = (n * (2 + ((n - 1) * 2))) / 2;
    llint target = tsum / n;
    llint answer = 0;

    for (llint i = 0, j = 1; i < n / 2; i++, j = (2 * i) + 1) {
      answer += (target - j);
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
