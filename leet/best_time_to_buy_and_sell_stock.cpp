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
  int maxProfit(vector<int>& prices) {
    const size_t size = prices.size();
    if (size == 0)
      return 0;
    int maxval = prices[size - 1];
    int answer = 0;
    for (int i = size - 1; i > -1; i--) {
      maxval = max(maxval, prices[i]);
      answer = max(answer, maxval - prices[i]);
    }
    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
