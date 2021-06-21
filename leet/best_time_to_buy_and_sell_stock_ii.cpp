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
    int high = prices[size - 1];
    int low = prices[size - 1];
    int answer = 0;
    for (int i = size - 2; i > -1; i--) {
      if (prices[i] >= high or prices[i] > low) {
        answer += (high - low);
        low = prices[i];
        high = low;
      } else if (prices[i] < low) {
        low = prices[i];
      }
    }
    if (high != low)
      answer += (high - low);
    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
