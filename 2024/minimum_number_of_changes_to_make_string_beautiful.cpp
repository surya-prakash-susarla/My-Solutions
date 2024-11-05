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
  int __rec__(int ind, const string& input) {
    if (ind == input.size())
      return 0;

    if (input[ind] != input[ind + 1]) {
      return 1 + __rec__(ind + 2, input);
    } else {
      return __rec__(ind + 2, input);
    }
  }

  int minChanges(string s) { return __rec__(0, s); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
