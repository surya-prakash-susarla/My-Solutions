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
  vector<int> twoSum(vector<int>& values, int target) {
    map<int, set<int>> temp;
    for (int i = 0; i < values.size(); i++)
      temp[values[i]].insert(i);

    for (int i = 0; i < values.size(); i++) {
      auto it = temp[target - values[i]].upper_bound(i);
      if (it != temp[target - values[i]].end())
        return {i, *it};
    }

    return {};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
