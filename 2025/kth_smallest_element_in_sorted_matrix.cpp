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
  int kthSmallest(vector<vector<int>>& values, int k) {
    typedef vector<int> vint;
    typedef vector<vint> vvint;

    map<int, int> counts;
    for (vint i : values)
      for (int j : i)
        counts[j]++;

    for (auto i : counts) {
      if (i.second < k) {
        k -= i.second;
      } else {
        return i.first;
      }
    }

    return INT_MIN;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
