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
  bool doesValidArrayExist(vector<int>& target) {
    const int n = target.size();
    const char begin = 'x';
    char prev = 'x';

    for (int i = 0; i < n; i++)
      if (i == n - 1)
        return (target[i] == 1 ? (prev != begin) : (prev == begin));
      else if (target[i] == 1)
        prev = (prev == 'x' ? 'y' : 'x');

    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
