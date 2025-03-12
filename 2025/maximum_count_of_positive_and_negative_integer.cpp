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
  int maximumCount(vector<int>& input) {
    int pos = 0;
    int neg = 0;
    for (int i : input) {
      if (i > 0)
        pos++;
      else if (i < 0)
        neg++;
    }

    return max(pos, neg);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
