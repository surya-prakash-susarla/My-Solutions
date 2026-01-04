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
  unordered_map<int, int> memo;

  int calc(int x) {
    auto it = memo.find(x);
    if (it != memo.end())
      return it->second;

    set<int> values = {1, x};

    for (int i = 2; i < (x / 2) + 1; i++) {
      if (not values.contains(i) and x % i == 0) {
        if (values.size() == 4) {
          values.insert(INT_MAX);
          break;
        }

        values.insert(i);
        values.insert(x / i);
      }
    }

    int answer = 0;
    if (values.size() == 4)
      answer = accumulate(values.begin(), values.end(), 0);

    memo[x] = answer;
    return answer;
  }

  int sumFourDivisors(vector<int>& input) {
    int x = 0;
    for (int i : input)
      x += calc(i);
    return x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
