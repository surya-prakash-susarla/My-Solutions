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
  int strStr(string source, string target) {
    hash<string> hasher;

    int th = hasher(target);

    for (int i = 0; i < source.size(); i++) {
      int ch = hasher(source.substr(i, target.size()));
      if (ch == th)
        return i;
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
