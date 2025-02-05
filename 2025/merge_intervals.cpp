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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    vvint answer;

    if (intervals.empty())
      return {};

    sort(intervals.begin(), intervals.end(), [](const vint& a, const vint& b) {
      if (a[0] == b[0])
        return a[1] < b[1];

      return a[0] < b[0];
    });

    vint current = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= current[1]) {
        current[1] = max(current[1], intervals[i][1]);
      } else {
        answer.emplace_back(current);
        current = intervals[i];
      }
    }

    answer.emplace_back(current);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
