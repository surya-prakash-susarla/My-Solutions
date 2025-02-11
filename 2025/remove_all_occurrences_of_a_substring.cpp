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
  string removeOccurrences(string s, string part) {
    int loc = s.find(part);
    if (loc == string::npos)
      return s;

    string prefix = s.substr(0, loc);
    string suffix = s.substr(loc + part.size(), s.size());

    return removeOccurrences(prefix + suffix, part);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
