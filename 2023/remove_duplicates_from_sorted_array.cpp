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
  int removeDuplicates(vector<int>& values) {
    constexpr int maxvalue = numeric_limits<int>::max();

    int lu = values[0];
    const int n = values.size();
    int count = 0;

    for (int i = 1; i < n; i++) {
      if (values[i] == lu) {
        count++;
        values[i] = maxvalue;
      } else {
        lu = values[i];
      }
    }

    sort(values.begin(), values.end());

    return n - count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
