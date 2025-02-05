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
  int findKthPositive(vector<int>& input, int k) {
    int prev = 0;
    for (int i = 0; i < input.size(); i++) {
      int diff = (input[i] - prev - 1);
      if (diff == 0) {
      } else {
        if (diff < k) {
          k -= diff;
        } else {
          return prev + k;
        }
      }
      prev = input[i];
    }

    return *input.rbegin() + k;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
