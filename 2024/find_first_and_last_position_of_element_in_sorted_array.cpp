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
  vector<int> searchRange(vector<int>& values, int target) {
    if (values.empty() or
        find(values.begin(), values.end(), target) == values.end())
      return {-1, -1};
    auto i = equal_range(values.begin(), values.end(), target);
    return {int(i.first - values.begin()),
            (int)(prev(i.second) - values.begin())};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
