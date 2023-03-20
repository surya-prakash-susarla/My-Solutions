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
  bool canPlaceFlowers(vector<int>& values, int n) {
    if (values.size() == 1)
      return (values[0] == 0 and n <= 1) or n == 0;

    if (values[0] == 0 and values[1] == 0) {
      values[0] = 1;
      n--;
    }
    if (values[values.size() - 1] == 0 and values[values.size() - 2] == 0) {
      values[values.size() - 1] = 1;
      n--;
    }

    for (int i = 1; i <= values.size() - 2; i++) {
      if (values[i] == 0 and values[i - 1] == 0 and values[i + 1] == 0) {
        values[i] = 1;
        n--;
      }
    }

    return n <= 0;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
