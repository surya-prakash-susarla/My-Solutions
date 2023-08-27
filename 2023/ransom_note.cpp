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
  bool canConstruct(string input, string values) {
    map<char, int> counts;
    for (char c : values)
      counts[c]++;

    map<char, int> req;
    for (char c : input)
      req[c]++;

    for (const pair<char, int>& i : req) {
      if (counts[i.first] < i.second)
        return false;
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
