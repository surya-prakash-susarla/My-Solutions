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
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int dist = max(abs(sx - fx), abs(sy - fy));

    if (dist == 0)
      return t >= 2 or t == 0;

    if (t < dist)
      return false;
    else if (t == dist)
      return true;
    else
      return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
