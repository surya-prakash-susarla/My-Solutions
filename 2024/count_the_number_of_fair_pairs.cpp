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
  long long countFairPairs(vector<int>& input, int lower, int upper) {
    sort(input.begin(), input.end());

    long long answer = 0;

    for (auto i = input.begin(); i != input.end(); i = next(i)) {
      auto lb = lower_bound(next(i), input.end(), lower - (*i));
      auto ub = upper_bound(next(i), input.end(), upper - (*i));
      answer += distance(lb, ub);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
