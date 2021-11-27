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
  int minPairSum(vector<int>& nums) {
    vector<int> values = nums;
    sort(values.begin(), values.end());

    typedef long long int llint;
    llint answer = 0;

    const int n = values.size();

    for (llint i = 0; i < n / 2; i++) {
      answer = max(answer, (llint)(values[i] + values[n - 1 - i]));
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
