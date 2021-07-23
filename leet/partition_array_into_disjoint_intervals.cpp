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
  int partitionDisjoint(vector<int>& nums) {
    const size_t size = nums.size();
    using vint = vector<int>;
    vint lmax(size), rmin(size);

    lmax[0] = nums[0];
    for (int i = 1; i < size; i++)
      lmax[i] = max(lmax[i - 1], nums[i]);

    rmin[size - 1] = nums[size - 1];
    for (int i = size - 2; i > -1; i--)
      rmin[i] = min(rmin[i + 1], nums[i]);

    int answer = numeric_limits<int>::max();
    for (int i = size - 2; i > -1; i--) {
      if (lmax[i] <= rmin[i + 1])
        answer = min(answer, i + 1);
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
