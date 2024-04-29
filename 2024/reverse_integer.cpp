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
  optional<int> mul(int x) {
    int answer = 0;
    for (int i = 0; i < 10; i++) {
      if (INT_MAX - answer >= x)
        answer += x;
      else
        return nullopt;
    }
    return answer;
  }

  int reverse(int x) {
    if (x == INT_MIN or x == INT_MAX)
      return 0;

    bool neg = (x < 0);
    if (neg)
      x = 0 - x;

    int answer = 0;
    while (x > 0) {
      int cdig = x % 10;
      x /= 10;
      optional<int> valp = mul(answer);
      if (not valp)
        return 0;
      int val = *valp;
      if (INT_MAX - val >= cdig) {
        answer = val + cdig;
      } else {
        answer = 0;
        break;
      }
    }

    return neg ? -answer : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
