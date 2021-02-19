#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>


// Problem:
// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Bi-weekly contest 228

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  int minOperations(string s) {
    int one_based = 0, zero_based = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i % 2 == 0) {
        if (s[i] == '1')
          zero_based++;
        else
          one_based++;
      } else {
        if (s[i] == '1')
          one_based++;
        else
          zero_based++;
      }
    }
    return min(one_based, zero_based);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
