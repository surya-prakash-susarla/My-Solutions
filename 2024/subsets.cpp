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
  vector<vector<int>> answer;

  void __rec__(int ind,
               vector<int> current,
               const vector<int>& values,
               bool first = false) {
    if (ind == values.size()) {
      answer.emplace_back(current);
      return;
    }
    if (first) {
      __rec__(ind + 1, {values[ind]}, values);
    } else {
      __rec__(ind + 1, current, values);
      current.push_back(values[ind]);
      __rec__(ind + 1, current, values);
    }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    answer.push_back({});
    for (int i = 0; i < nums.size(); i++)
      __rec__(i, {}, nums, true);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
