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
  int minimumAverageDifference(vector<int>& values) {
    typedef long long llint;
    llint full_sum = 0;
    for (int i : values)
      full_sum += i;

    llint current_sum = 0;
    llint answer = numeric_limits<llint>::max();
    llint index = -1;
    llint n = values.size();

    for (int i = 0; i < values.size() - 1; i++) {
      current_sum += values[i];
      llint rem_sum = full_sum - current_sum;
      llint cdiff =
          abs(floor(current_sum / (i + 1)) - floor(rem_sum / (n - 1 - i)));
      if (cdiff < answer) {
        answer = cdiff;
        index = i;
      }
    }

    if ((full_sum / n) < answer) {
      answer = full_sum;
      index = values.size() - 1;
    }

    return index;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
