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
  inline optional<pair<int, int>> overlap(const pair<int, int>& a,
                                          const vector<int>& b) {
    if (b[0] > a.second)
      return nullopt;
    return make_pair(max(a.first, b[0]), min(a.second, b[1]));
  }

  int findMinArrowShots(vector<vector<int>>& input) {
    sort(input.begin(), input.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] < b[0];
         });

    int answer = 0;
    int index = 0;

    while (index < input.size()) {
      answer++;
      pair<int, int> current = {input[index][0], input[index][1]};
      int ni = input.size();

      for (int j = index + 1; j < input.size(); j++) {
        auto ov = overlap(current, input[j]);
        if (ov) {
          current = *ov;
        } else {
          ni = j;
          break;
        }
      }

      index = ni;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
