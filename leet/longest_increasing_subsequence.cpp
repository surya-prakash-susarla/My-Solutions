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

  int lengthOfLIS(vector<int>& input) {
    const size_t& size = input.size();

    vint memo(size, 0);

    memo[size - 1] = 1;
    int answer = 1;

    for (int i = size - 2; i >= 0; i--) {
      int maxval = 1;
      for (int j = i + 1; j < size; j++) {
        if (input[i] < input[j]) {
          maxval = max(maxval, memo[j] + 1);
        }
      }
      memo[i] = maxval;
      answer = max(answer, maxval);
    }
    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
