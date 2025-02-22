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
  unordered_set<string> values;

  void __rec__(int ind, const string& input, string current) {
    if (ind == input.size()) {
      values.insert(current);
      return;
    }

    __rec__(ind + 1, input, current + input[ind]);
    __rec__(ind + 1, input, current);
  }

  int numTilePossibilities(string tiles) {
    sort(tiles.begin(), tiles.end());

    while (next_permutation(tiles.begin(), tiles.end()))
      __rec__(0, tiles, "");

    return values.size() ? values.size() : tiles.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
