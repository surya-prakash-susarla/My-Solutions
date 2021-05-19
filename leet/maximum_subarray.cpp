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
  int maxSubArray(vector<int>& nums) {
    int ns = 0;
    int answer = -100001;
    for (int i = nums.size() - 1; i >= 0; i--) {
      ns = max(nums[i], nums[i] + ns);
      answer = max(answer, ns);
    }
    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
