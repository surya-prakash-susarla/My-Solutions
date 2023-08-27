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
  bool containsNearbyDuplicate(vector<int>& input, int k) {
    map<int, vector<int>> temp;
    for (int i = 0; i < input.size(); i++) {
      temp[input[i]].push_back(i);
    }

    for (const pair<int, vector<int>>& i : temp) {
      for (int j = 1; j < i.second.size(); j++) {
        if (i.second[j] - i.second[j - 1] <= k)
          return true;
      }
    }

    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
