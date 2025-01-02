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
  static const int modval = 1000000007;
  typedef long long int llint;

  unordered_map<int, llint> memo;

  llint __rec__(int len,
                const int low,
                const int high,
                const int zero,
                const int one) {
    auto it = memo.find(len);
    if (it != memo.end()) {
      return it->second;
    }

    llint answer = 0;

    if (len >= low and len <= high)
      answer++;
    answer %= modval;

    if (len + zero <= high)
      answer += __rec__(len + zero, low, high, zero, one);
    answer %= modval;

    if (len + one <= high)
      answer += __rec__(len + one, low, high, zero, one);
    answer %= modval;

    memo[len] = answer;

    return answer;
  }

  int countGoodStrings(int low, int high, int zero, int one) {
    return __rec__(0, low, high, zero, one);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
