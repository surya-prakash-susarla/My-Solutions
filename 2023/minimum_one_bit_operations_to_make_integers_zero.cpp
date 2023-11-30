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
  int __rec__(const bitset<32> value, const int ind, const int req) {
    if (ind == 0)
      return value[ind] == req ? 0 : 1;
    else if (value[ind] == req)
      return __rec__(value, ind - 1, 0);
    else
      return 1 + __rec__(value, ind - 1, 1) + ((1 << ind) - 1);
  }

  int minimumOneBitOperations(int n) { return __rec__(bitset<32>(n), 31, 0); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
