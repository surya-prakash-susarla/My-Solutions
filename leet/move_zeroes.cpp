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
  void moveZeroes(vector<int>& nums) {
    for (int i = 0, old = -1; i < nums.size(); i++) {
      if (nums[i] != 0 and old != -1) {
        nums[old] = nums[i];
        nums[i] = 0;
        old++;
      } else if (nums[i] == 0 and old == -1)
        old = i;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
