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
  int partitionString(string values) {
    map<char, bool> memo;

    int count = 1;

    for (char c : values) {
      if (memo[c]) {
        count++;
        memo.clear();
        memo[c] = true;
      } else {
        memo[c] = true;
      }
    }

    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
