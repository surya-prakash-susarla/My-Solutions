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
  int maxLength(vector<int>& input, int k) {
    int minvalue = 1;
    int maxvalue = input[0];
    for (int i : input)
      maxvalue = max(maxvalue, i);

    typedef unsigned long long ull;
    ull sum = 0;
    for (int i : input)
      sum += i;
    if (sum < k)
      return 0;
    else if (sum == k)
      return 1;

    int left = 1;
    int right = maxvalue;

    typedef vector<int> vint;

    auto is_valid = [](const vint& input, int x, int k) -> bool {
      int count = 0;
      for (int i : input) {
        count += (i / x);
        if (count >= k)
          return true;
      }
      return count >= k;
    };

    int answer = 0;
    while (left <= right) {
      int current = (left + right) / 2;
      if (is_valid(input, current, k)) {
        answer = max(answer, current);
        left = current + 1;
      } else {
        right = current - 1;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
