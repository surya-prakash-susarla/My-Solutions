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
  bool checkSubarraySum(vector<int>& values, int k) {
    unordered_map<int, int> rem;

    int pre = 0;

    rem[0] = -1;

    for (int i = 0; i < values.size(); i++) {
      pre += values[i];
      pre %= k;
      auto it = rem.find(pre);
      if (it != rem.end() and i - it->second > 1)
        return true;

      if (it == rem.end())
        rem[pre] = i;
    }

    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
