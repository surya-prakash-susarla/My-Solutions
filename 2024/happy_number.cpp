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
  bool isHappy(int n) {
    set<int> covered;
    int current = n;
    while (current != 1) {
      int next = 0;
      while (current) {
        next += ((current % 10) * (current % 10));
        current /= 10;
      }
      if (covered.contains(next))
        return false;
      current = next;
      covered.insert(current);
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
