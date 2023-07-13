#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  int n;
  vector<int> values;
  vector<int> memo;

  int __rec__(int index, int current_price, int price_held) {
    if (index >= n)
      return current_price;
    if (price_held != -1) {
      // Since we are holding we have 2 options.
      int sell = 0;
      if (values[index] > price_held) {
        // sell today.
        sell = (values[index] - price_held) +
               __rec__(index + 2, current_price, -1);
      }
      // skip.
      int skip = __rec__(index + 1, current_price, price_held);
      return max(sell, skip);
    } else {
      if (memo[index] != -1)
        return memo[index];

      // we can potentially buy stuff here.
      // 1. skip today
      int skip = __rec__(index + 1, current_price, -1);

      // 2. buy today
      int buy = __rec__(index + 1, current_price, values[index]);

      memo[index] = max(skip, buy);

      return memo[index];
    }
  }

  int maxProfit(vector<int>& prices) {
    n = prices.size();
    values = prices;
    memo = vector<int>(n, -1);
    return __rec__(0, 0, -1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
