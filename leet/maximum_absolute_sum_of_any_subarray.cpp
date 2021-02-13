#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>

// Problem: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  int answer = -1;

  inline bool is_same_sign(const int& a, const int& b) {
    return ((a < 0 && b < 0) || (a > 0 && b > 0));
  }

  int maxAbsoluteSum(vector<int>& nums) {
    // the below combination of successive same digit numbers can be removed to
    // speed things up.
    vector<int> input;
    for (const int i : nums) {
      if (input.size() > 0 && is_same_sign(i, input.back())) {
        *input.rbegin() = input.back() + i;
      } else {
        input.push_back(i);
      }
    }

    const int size = input.size();

    using pint = pair<int, int>;

    vector<pint> values(size, {0, 0});

    values[size - 1] = input[size - 1] > 0 ? pint(input[size - 1], 0)
                                           : pint(0, input[size - 1]);
    answer =
        max({answer, values[size - 1].first, abs(values[size - 1].second)});

    for (int i = size - 2; i >= 0; i--) {
      int& first = values[i].first;
      int& second = values[i].second;
      first = input[i] + values[i + 1].first;
      second = input[i] + values[i + 1].second;
      first = first > 0 ? first : 0;
      second = second < 0 ? second : 0;
      answer = max({answer, first, abs(second)});
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> values(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i];
  }
  std::cout << (new Solution)->maxAbsoluteSum(values) << std::endl;
  return 0;
}
