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
  inline bool is_perfect_square(int a) {
    return (ceil(sqrt(a)) == floor(sqrt(a)));
  }

  bool judgeSquareSum(int c) {
    typedef long long int llint;
    for (llint i = 0; i <= c; i++) {
      const llint req = c - (i * i);
      if (req < 0)
        return false;
      if (is_perfect_square(req))
        return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
