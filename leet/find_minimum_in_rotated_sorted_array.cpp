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
  int findMin(vector<int>& nums) {
    if (nums.size() == 1 or *nums.begin() < *nums.rbegin())
      return *nums.begin();

    for (int i = 1; i < nums.size(); i++)
      if (nums[i] < nums[i - 1])
        return nums[i];

    return nums[0];
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
