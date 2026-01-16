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
  long long maxMatrixSum(vector<vector<int>>& input) {
    typedef long long ll;
    int minval = INT_MAX;
    int nc = 0;
    ll sum = 0;

    for (auto i : input) {
      for (auto j : i) {
        if (j < 0) {
          nc++;
        }
        int a = abs(j);
        sum += a;
        minval = min(minval, a);
      }
    }

    if (nc % 2)
      sum -= 2 * minval;

    return sum;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
