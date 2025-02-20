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
  int target;
  vector<int> input;

  int __rec__(int left, int right) {
    if (left > right)
      return -1;

    int current = (left + right) / 2;
    if (input[current] == target)
      return current;

    if (input[left] < input[current] and input[current] < input[right]) {
      // fully sorted range.
      if (target < input[current]) {
        return __rec__(left, current - 1);
      } else {
        return __rec__(current + 1, right);
      }
    } else if (input[left] > input[current]) {
      // pivot on the left.
      if (target < input[current]) {
        return __rec__(left, current - 1);
      } else {
        if (target <= input[right]) {
          return __rec__(current + 1, right);
        } else {
          return __rec__(left, current - 1);
        }
      }
    } else {
      // pivot on the right.
      if (target < input[current]) {
        if (target < input[left]) {
          return __rec__(current + 1, right);
        } else {
          return __rec__(left, current - 1);
        }
      } else {
        return __rec__(current + 1, right);
      }
    }
  }

  int search(vector<int>& input, int target) {
    this->input = input;
    this->target = target;
    return __rec__(0, input.size() - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
