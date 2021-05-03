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

  vector<vint> answers;

  void __rec__(const int& index,
               vint& values,
               const int& csum,
               const vint& input,
               const int& target) {
    if (csum == target) {
      answers.push_back(values);
      return;
    } else if (csum > target || index >= input.size()) {
      return;
    }

    __rec__(index + 1, values, csum, input, target);

    for (int mul = 1; (mul * input[index]) + csum <= target; mul++) {
      for (int i = 0; i < mul; i++) {
        values.push_back(input[index]);
      }
      __rec__(index + 1, values, csum + mul * input[index], input, target);

      for (int i = 0; i < mul; i++) {
        values.pop_back();
      }
    }

    return;
  }

  vector<vint> combinationSum(vint& candidates, int target) {
    vint temp;
    __rec__(0, temp, 0, candidates, target);
    return std::move(answers);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
