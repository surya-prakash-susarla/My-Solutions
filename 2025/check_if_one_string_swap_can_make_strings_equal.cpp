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
  bool areAlmostEqual(string a, string b) {
    if (a == b)
      return true;

    bool swap_init = false;
    bool swap_done = false;
    char swap_source;
    char swap_target;

    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        if (swap_done) {
          return false;
        } else if (swap_init) {
          if (swap_source != a[i]) {
            return false;
          }
          if (swap_target != b[i]) {
            return false;
          }
          swap_done = true;
        } else {
          swap_init = true;
          swap_target = a[i];
          swap_source = b[i];
        }
      }
    }

    if (swap_init && !swap_done)
      return false;

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
