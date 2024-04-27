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

    sort(intervals.begin(), intervals.end(), [](const vint& a, const vint& b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      } else {
        return a[0] < b[0];
      }
    });

    vvint answer;

    vint current_interval = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
      vint next_interval = intervals[i];

      if (current_interval[1] >= next_interval[0]) {
        current_interval[1] = max(current_interval[1], next_interval[1]);
      } else {
        answer.emplace_back(current_interval);
        swap(current_interval, next_interval);
      }
    }

    answer.emplace_back(current_interval);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
