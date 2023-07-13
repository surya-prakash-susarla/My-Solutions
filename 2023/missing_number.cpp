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
  int missingNumber(vector<int>& values) {
    sort(values.begin(), values.end());
    if (values[0] != 0)
      return 0;
    for (int i = 1; i < values.size(); i++) {
      if (values[i] - values[i - 1] > 1)
        return values[i] - 1;
    }
    return values.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
