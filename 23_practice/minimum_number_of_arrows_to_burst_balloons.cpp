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
  typedef pair<int, int> pint;

  optional<vint> wrapper(const vint& a, const vint& b) {
    if (a[0] >= b[0] and a[0] <= b[1]) {
      return vint{a[0], min(b[1], a[1])};
    }
    if (a[1] >= b[0] and a[1] <= b[1]) {
      return vint{max(a[0], b[0]), a[1]};
    }
    return nullopt;
  }

  optional<vint> are_connected(const vint& a, const vint& b) {
    optional<vint> return_value = wrapper(a, b);
    if (return_value)
      return return_value;
    return_value = wrapper(b, a);
    return return_value;
  }

  int findMinArrowShots(vector<vector<int>>& values) {
    sort(values.begin(), values.end(), [](const vint& a, const vint& b) {
      if (a[0] == b[0])
        return a[1] < b[1];
      return a[0] < b[0];
    });

    vector<bool> visited(values.size(), false);
    int answer = 0;
    for (int i = 0; i < values.size(); i++) {
      if (not visited[i]) {
        answer++;
        vint current = values[i];
        visited[i] = true;
        for (int j = 0; j < values.size(); j++) {
          if (visited[j] or j == i)
            continue;
          optional<vint> temp = are_connected(current, values[j]);
          if (temp) {
            visited[j] = true;
            current = *temp;
          } else {
            break;
          }
        }
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
