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
  int rob(vector<int>& nums) {
    const size_t& size = nums.size();
    if (size == 1)
      return nums[0];
    vector<int> best(nums.size(), 0);
    best[size - 1] = nums[size - 1];
    best[size - 2] = max(nums[size - 1], nums[size - 2]);

    for (int i = nums.size() - 3; i > -1; i--) {
      const int inc = nums[i] + best[i + 2];
      const int exc = best[i + 1];
      best[i] = max(inc, exc);
    }

    return *max_element(best.begin(), best.end());
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
