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
  vector<vector<int>> memo;

  int __rec__(int index, int prev_index, const vector<int>& input) {
    if (memo[index][prev_index] != -1) {
      return memo[index][prev_index];
    }
    const int required_value = input[index] + input[prev_index];
    auto it =
        lower_bound(input.begin() + index + 1, input.end(), required_value);

    int answer = 1;
    if (it == input.end()) {
      answer = 1;
    } else if (*it != required_value) {
      answer = 1;
    } else {
      answer = 1 + __rec__(it - input.begin(), index, input);
    }
    memo[index][prev_index] = answer;
    return answer;
  }

  int lenLongestFibSubseq(vector<int>& input) {
    memo = vector<vector<int>>(input.size(), vector<int>(input.size(), -1));
    int answer = 0;

    for (int i = 0; i < input.size(); i++) {
      for (int j = i + 1; j < input.size(); j++) {
        int current = 1 + __rec__(j, i, input);
        if (current < 3)
          current = 0;
        answer = max(answer, current);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
