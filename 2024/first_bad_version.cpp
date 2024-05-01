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

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    long long int left = 1;
    long long int right = n;

    while (left < right) {
      long long int mid = (left + right) / 2;
      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
