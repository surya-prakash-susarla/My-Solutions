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
  string largestOddNumber(string input) {
    for (int i = input.size() - 1; i > -1; i--)
      if ((input[i] - '0') % 2)
        return input.substr(0, i + 1);
    return "";
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
