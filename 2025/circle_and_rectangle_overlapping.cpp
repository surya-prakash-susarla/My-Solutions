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
  bool
  checkOverlap(int radius, int rx, int ry, int x1, int y1, int x2, int y2) {
    int px = -1;
    if (rx >= x1 and rx <= x2) {
      px = rx;
    } else if (rx < x1) {
      px = x1;
    } else {
      px = x2;
    }

    int py = -1;
    if (ry >= y1 and ry <= y2) {
      py = ry;
    } else if (ry < y1) {
      py = y1;
    } else {
      py = y2;
    }

    return (pow(px - rx, 2) + pow(py - ry, 2) <= pow(radius, 2));
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
