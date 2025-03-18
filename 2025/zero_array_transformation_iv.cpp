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
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  bool __rec__(int i,
               const vector<int>& values,
               int req,
               vector<vector<int>>& memo) {
    if (i == values.size()) {
      return req == 0;
    }
    if (req == 0)
      return true;
    if (req < 0)
      return false;

    if (memo[i][req] != -1)
      return memo[i][req] == 1;

    const bool answer = __rec__(i + 1, values, req - values[i], memo) or
                        __rec__(i + 1, values, req, memo);
    memo[i][req] = (answer ? 1 : 0);
    return answer;
  }

  bool is_valid(const vint& input, const vvint& request, int k) {
    vvint values(input.size());
    for (int i = 0; i < k; i++) {
      for (int j = request[i][0]; j <= request[i][1]; j++)
        values[j].push_back(request[i][2]);
    }

    for (int i = 0; i < input.size(); i++) {
      vector<vector<int>> memo(values[i].size() + 1,
                               vector<int>(input[i] + 1, -1));
      if (not __rec__(0, values[i], input[i], memo))
        return false;
    }

    return true;
  }

  int minZeroArray(vector<int>& input, vector<vector<int>>& request) {
    int left = 0;
    int right = request.size();

    int answer = INT_MAX;
    while (left <= right) {
      int current = (left + right) / 2;
      if (is_valid(input, request, current)) {
        answer = min(answer, current);
        right = current - 1;
      } else {
        left = current + 1;
      }
    }
    return answer == INT_MAX ? -1 : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
