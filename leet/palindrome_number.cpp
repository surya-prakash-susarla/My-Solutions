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
#include <string>
#include <utility>
#include <vector>


// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    string orig = to_string(x);
    string rev = orig;
    reverse(rev.begin(), rev.end());
    return orig == rev;
    // return orig == reverse(orig.begin(), orig.end());
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
