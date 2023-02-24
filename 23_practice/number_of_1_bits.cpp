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
  int hammingWeight(uint32_t n) {
    bitset<32> values(n);
    return values.count();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
