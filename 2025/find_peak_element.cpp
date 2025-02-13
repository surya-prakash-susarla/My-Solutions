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

  int __rec__(int i, const vint& values) {
    if (i - 1 > -1 and values[i - 1] > values[i])
      return __rec__(i - 1, values);
    if (i + 1 < values.size() and values[i + 1] > values[i])
      return __rec__(i + 1, values);
    return i;
  }

  int findPeakElement(vector<int>& values) {
    return __rec__(values.size() / 2, values);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
