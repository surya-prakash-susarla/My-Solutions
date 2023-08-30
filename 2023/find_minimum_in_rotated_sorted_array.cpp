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
  int minvalue = numeric_limits<int>::max();

  void __rec__(int start, int end, const vector<int>& values) {
    if (start == end) {
      minvalue = min(minvalue, values[start]);
      return;
    }
    if (start > end)
      return;

    if (end - start == 1) {
      minvalue = min({minvalue, values[start], values[end]});
      return;
    }

    int mid = (start + end) / 2;
    if (values[start] > values[mid])
      __rec__(start, mid, values);
    else
      __rec__(mid, end, values);
  }

  int findMin(vector<int>& values) {
    if (values[0] < *values.rbegin())
      return values[0];

    __rec__(0, values.size() - 1, values);

    return minvalue;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
