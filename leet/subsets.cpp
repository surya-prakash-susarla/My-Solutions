#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  typedef vector<int> vint;
  typedef vector<vint> vvint;

  vvint answer;

  void __rec__(const vint& values, const int index) {
    if (index == values.size())
      return;

    __rec__(values, index + 1);

    const int& csize = answer.size();

    const int& current = values[index];
    answer.push_back({current});

    for (int i = 0; i < csize; i++) {
      vint temp = answer[i];
      temp.push_back(current);
      answer.push_back(temp);
    }

    return;
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    __rec__(nums, 0);
    answer.push_back({});
    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}

