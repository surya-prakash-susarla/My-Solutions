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
  int computeArea(int ax1,
                  int ay1,
                  int ax2,
                  int ay2,
                  int bx1,
                  int by1,
                  int bx2,
                  int by2) {
    int first = (ax2 - ax1) * (ay2 - ay1);
    int second = (bx2 - bx1) * (by2 - by1);

    auto is_between = [](int target, int l1, int l2) -> bool {
      return target >= l1 and target <= l2;
    };

    auto get_dim = [&](int a1, int a2, int b1, int b2) -> int {
      int dim = 0;
      if (is_between(b1, a1, a2)) {
        dim = min(a2, b2) - b1;
      } else if (is_between(b2, a1, a2)) {
        dim = b2 - a1;
      } else if (is_between(a1, b1, b2) and is_between(a2, b1, b2)) {
        dim = a2 - a1;
      }
      return dim;
    };

    // overlap
    int x_dim = get_dim(ax1, ax2, bx1, bx2);
    int y_dim = get_dim(ay1, ay2, by1, by2);

    return (first + second) - (x_dim * y_dim);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
