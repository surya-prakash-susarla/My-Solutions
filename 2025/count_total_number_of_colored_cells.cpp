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
  long long coloredCells(int n) {
    long long x = n;
    return (2 * x * x) - (2 * x) + 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
