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
  vector<int> input;
  vector<int> memo;

  int __rec__(int ind) {
    if (ind >= input.size() - 1) {
      return 0;
    }

    if (memo[ind] != -1)
      return memo[ind];

    int answer = INT_MAX;
    for (int i = 1; i <= input[ind]; i++) {
      int dist = __rec__(ind + i);
      if (dist != INT_MAX)
        dist += 1;
      answer = min(answer, dist);
    }

    memo[ind] = answer;
    return answer;
  }

  int jump(vector<int>& input) {
    this->input = input;
    memo = vector<int>(input.size(), -1);

    return __rec__(0);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
