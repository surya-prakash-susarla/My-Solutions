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
  bool isIsomorphic(string a, string b) {
    map<char, char> temp;

    for (int i = 0; i < a.size(); i++) {
      auto it = temp.find(a[i]);
      if (it != temp.end()) {
        if (it->second == b[i])
          continue;
        else
          return false;
      } else {
        for (auto j : temp)
          if (j.second == b[i])
            return false;
        temp[a[i]] = b[i];
      }
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
