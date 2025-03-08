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
  bool is_valid(const vector<int>& input, int weight, int days) {
    int current = 0;
    int csum = 0;
    for (int i : input) {
      if (csum + i > weight) {
        current++;
        csum = i;
      } else {
        csum += i;
      }
    }
    current++;
    return current <= days;
  }

  int shipWithinDays(vector<int>& input, int days) {
    int right = 0;
    int left = input[0];
    for (int i : input) {
      right += i;
      left = max(left, i);
    }

    int answer = right;
    while (left <= right) {
      int current = (left + right) / 2;
      if (is_valid(input, current, days)) {
        answer = current;
        right = current - 1;
      } else {
        left = current + 1;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
