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
  typedef pair<int, int> pint;
  typedef vector<int> vint;

  optional<pint> __rec__(int start,
                         int end,
                         const vint& values,
                         const int target) {
    if (start > end)
      return nullopt;
    if (start == end)
      return values[start] == target ? optional<pint>(make_pair(start, start))
                                     : nullopt;

    int mid = (start + end) / 2;
    if (values[mid] < target) {
      return __rec__(mid + 1, end, values, target);
    } else if (values[mid] > target) {
      return __rec__(start, mid - 1, values, target);
    } else {
      optional<pint> left = __rec__(start, mid - 1, values, target);
      optional<pint> right = __rec__(mid + 1, end, values, target);
      pint answer;
      answer.first = left.has_value() ? left->first : mid;
      answer.second = right.has_value() ? right->second : mid;
      return answer;
    }
  }

  vector<int> searchRange(vector<int>& values, int target) {
    optional<pint> answer = __rec__(0, values.size() - 1, values, target);
    return answer.has_value() ? vint({answer->first, answer->second})
                              : vint({-1, -1});
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
