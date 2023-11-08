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
  set<vint> answer;

  void __rec__(const vint& values, int index, vint solution) {
    if (index == values.size()) {
      answer.insert(solution);
      return;
    }
    __rec__(values, index + 1, solution);

    solution.push_back(values[index++]);

    __rec__(values, index, solution);
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    __rec__(nums, 0, {});
    return vector<vint>(answer.begin(), answer.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
