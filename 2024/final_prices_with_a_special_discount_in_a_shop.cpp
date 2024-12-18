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
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> answer;

    for (int i = prices.size() - 1; i > -1; i--) {
      bool done = false;
      for (int j = i + 1; j < prices.size(); j++) {
        if (prices[j] <= prices[i]) {
          done = true;
          answer.push_back(prices[i] - prices[j]);
          break;
        }
      }
      if (not done)
        answer.push_back(prices[i]);
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
