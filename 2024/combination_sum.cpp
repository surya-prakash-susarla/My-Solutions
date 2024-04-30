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

  vvint answer;

  void __rec__(int index, int req, vint current, const vint& values) {
    if (req == 0) {
      answer.emplace_back(current);
      return;
    }
    if (index == values.size())
      return;

    __rec__(index + 1, req, current, values);

    for (int i = 1;; i++) {
      current.push_back(values[index]);
      if (req - (values[index] * i) < 0)
        return;
      __rec__(index + 1, req - (values[index] * i), current, values);
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    __rec__(0, target, {}, candidates);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
