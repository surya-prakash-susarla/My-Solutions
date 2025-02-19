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

  void __rec__(int index, vint current, const vint& input, int req) {
    if (req < 0) {
      return;
    }
    if (req == 0) {
      answer.emplace_back(current);
      return;
    }

    if (index >= input.size())
      return;

    __rec__(index + 1, current, input, req);

    int count = 1;
    while (input[index] * count <= req) {
      current.push_back(input[index]);
      __rec__(index + 1, current, input, req - (input[index] * count));
      count++;
    }
  }

  vector<vector<int>> combinationSum(vector<int>& input, int target) {
    __rec__(0, {}, input, target);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
