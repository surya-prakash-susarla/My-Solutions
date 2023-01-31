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
  static constexpr int maxvalue = numeric_limits<int>::max();

  vector<int> values;
  vector<vector<int>> memo;

  int __rec__(int index, int req) {
    if (req == 0)
      return 0;
    if (index < 0)
      return maxvalue;
    if (memo[index][req] != -1)
      return memo[index][req];
    int answer = maxvalue;
    for (int i = req / values[index]; i > -1; i--) {
      int current_req = req - (values[index] * i);
      int current_answer = __rec__(index - 1, current_req);
      current_answer =
          current_answer == maxvalue ? maxvalue : current_answer + i;
      answer = min(answer, current_answer);
    }
    memo[index][req] = answer;
    return answer;
  }

  int coinChange(vector<int>& coins, int amount) {
    values = coins;
    memo = vector<vector<int>>(12, vector<int>(10001, -1));
    int answer = __rec__(coins.size() - 1, amount);
    return answer == maxvalue ? -1 : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
