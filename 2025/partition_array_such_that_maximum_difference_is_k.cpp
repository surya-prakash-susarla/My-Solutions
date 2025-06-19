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
  int calc(int i, int j, const vector<int>& values, const int k) {
    if (i >= j)
      return 0;

    if (values[j] - values[i] > k) {
      auto it = upper_bound(next(values.begin(), i), next(values.begin(), j),
                            values[i] + k);
      return 1 + calc(it - values.begin(), j, values, k);
    } else {
      return 0;
    }
  }

  int partitionArray(vector<int>& input, int k) {
    sort(input.begin(), input.end());
    return calc(0, input.size() - 1, input, k) + 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
