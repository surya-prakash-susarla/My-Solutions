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
  vector<int> twoSum(vector<int>& values, int target) {
    vector<int> answer(2, -1);

    for (int i = 0; i < values.size(); i++) {
      int req = target - values[i];
      if (req < values[i]) {
        auto it = lower_bound(values.begin(), values.begin() + i, req);
        if (it != values.end() && *it + values[i] == target) {
          answer[0] = i + 1;
          answer[1] = (it - values.begin()) + 1;
          return answer;
        }
      } else {
        auto it = lower_bound(values.begin() + i + 1, values.end(), req);
        if (it != values.end() && *it + values[i] == target) {
          answer[0] = i + 1;
          answer[1] = (it - values.begin()) + 1;
          return answer;
        }
      }
    }

    return {};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
