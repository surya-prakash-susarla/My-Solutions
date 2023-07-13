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
  int minSubArrayLen(int target, vector<int>& values) {
    int left = 0;
    int right = 0;
    int answer = values.size();
    int temp = 0;

    while (left <= right and right < values.size()) {
      if (temp < target) {
        temp += values[right++];
      } else {
        answer = min(answer, right - left);
        temp -= values[left++];
      }
    }

    for (;;) {
      if (temp > target and temp - values[left] >= target) {
        temp -= values[left++];
      } else {
        break;
      }
    }

    answer = min(answer, right - left);

    if (answer == values.size() and temp < target)
      return 0;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
