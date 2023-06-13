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
  int maxProfit(vector<int>& prices) {
    const size_t size = prices.size();
    int high = prices[size - 1];
    int low = prices[size - 1];
    int answer = 0;
    for (int i = size - 2; i > -1; i--) {
      if (prices[i] > low) {
        answer += (high - low);
        low = prices[i];
        high = low;
      } else {
        low = prices[i];
      }
    }
    if (high != low)
      answer += (high - low);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
