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
  bool isUgly(int n) {
    int value = n;

    if (value <= 0)
      return false;

    while (value != 1) {
      if (value % 2 == 0)
        value /= 2;
      else if (value % 3 == 0)
        value /= 3;
      else if (value % 5 == 0)
        value /= 5;
      else
        return false;
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
