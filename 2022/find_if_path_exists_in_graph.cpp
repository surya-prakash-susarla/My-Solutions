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
  unordered_map<int, set<int>> values;
  vector<bool> usage;

  bool __rec__(int current, int target) {
    if (current == target)
      return true;
    usage[current] = true;
    for (int i : values[current])
      if (not usage[i] and __rec__(i, target))
        return true;
    return false;
  }

  bool validPath(int n,
                 vector<vector<int>>& edges,
                 int source,
                 int destination) {
    usage = vector<bool>(n, false);
    for (const vector<int>& i : edges) {
      values[i[0]].insert(i[1]);
      values[i[1]].insert(i[0]);
    }
    return __rec__(source, destination);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
