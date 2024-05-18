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
  int kthFactor(int n, int k) {
    for (int i = 1; i <= n; i++)
      if (n % i == 0) {
        k--;
        if (k == 0)
          return i;
      }
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
