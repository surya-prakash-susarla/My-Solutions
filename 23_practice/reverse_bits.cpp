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
  uint32_t reverseBits(uint32_t n) {
    bitset<32> original(n);
    string temp = original.to_string();
    reverse(temp.begin(), temp.end());
    bitset<32> conversion(temp);
    return static_cast<uint32_t>(conversion.to_ulong());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
