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
  int maxSubArray(vector<int>& values) {
    int answer = numeric_limits<int>::min();
    int prevmax = 0;

    for (int i : values) {
      int cmax = prevmax + i;
      answer = max(answer, cmax);
      if (cmax < 0) {
        prevmax = 0;
        continue;
      }
      prevmax = cmax;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
