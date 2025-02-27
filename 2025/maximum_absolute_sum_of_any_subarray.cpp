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
  int maxAbsoluteSum(vector<int>& input) {
    const int n = input.size();
    vector<int> minvals(n);
    vector<int> maxvals(n);

    minvals[n - 1] = input[n - 1];
    maxvals[n - 1] = input[n - 1];

    int answer = max({0, abs(minvals[n - 1]), abs(maxvals[n - 1])});

    for (int i = n - 2; i > -1; i--) {
      int minval = min(input[i], input[i] + minvals[i + 1]);
      int maxval = max(input[i], input[i] + maxvals[i + 1]);

      answer = max({answer, abs(minval), abs(maxval)});

      minvals[i] = minval;
      maxvals[i] = maxval;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
