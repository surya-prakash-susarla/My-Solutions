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
  bool rotateString(string s, string goal) {
    if (s == goal)
      return true;

    for (int i = 1; i < goal.size(); i++) {
      const string left = goal.substr(0, i);
      const string right = goal.substr(i, s.size());
      if (right + left == s)
        return true;
    }

    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
