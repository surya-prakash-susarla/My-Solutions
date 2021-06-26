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
  using vint = vector<int>;
  using vvint = vector<vint>;

  vint input;
  vvint memo;

  int __rec__(const int index, const bool fu) {
    if (index >= input.size())
      return 0;

    const int conv = fu ? 1 : 0;

    int& mem = memo[index][conv];

    if (mem != -1)
      return mem;

    if (index == input.size() - 1) {
      mem = fu ? 0 : input[index];
      return mem;
    }

    const int inc = input[index] + __rec__(index + 2, fu or index == 0);
    const int exc = __rec__(index + 1, fu);

    mem = max(inc, exc);
    return mem;
  }

  int rob(vector<int>& nums) {
    input = nums;
    memo = vvint(nums.size(), vint(2, -1));
    return __rec__(0, false);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
