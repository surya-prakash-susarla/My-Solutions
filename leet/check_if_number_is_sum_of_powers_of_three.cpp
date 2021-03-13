#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>


// Problem: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/submissions/

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<bool> used;

  bool checkPowersOfThree(int n) {
    if (n == 1 || n == 0)
      return true;

    if (used.empty()) {
      used = vector<bool>(n, false);
    }

    int answer = -1;

    for (int i = 1; i < n; i++) {
      int powered = pow(3, i);
      if (powered > n) {
        break;
      } else if (!used[i]) {
        answer = i;
      }
    }

    if (answer == -1)
      return false;
    else {
      used[answer] = true;
      return checkPowersOfThree(n - pow(3, answer));
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
