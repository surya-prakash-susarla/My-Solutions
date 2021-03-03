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


// Problem:
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  int minPartitions(string n) {
    int highest = -1;
    for (const char& i : n) {
      int temp = i - '0';
      highest = max(highest, temp);
    }
    return highest;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
