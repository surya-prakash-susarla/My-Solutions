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
  int __rec__(int start, int end, const vector<int>& values, const int target) {
    if (start > end)
      return -1;

    int mid = (start + end) / 2;
    int midvalue = values[mid];
    if (target == midvalue)
      return mid;
    if (midvalue > values[end] and (target > midvalue or target <= values[end]))
      return __rec__(mid + 1, end, values, target);
    if (midvalue < values[start] and
        (target >= values[start] or target < midvalue))
      return __rec__(start, mid - 1, values, target);
    if (target < midvalue)
      return __rec__(start, mid - 1, values, target);
    else
      return __rec__(mid + 1, end, values, target);
  }

  int search(vector<int>& values, int target) {
    return __rec__(0, values.size() - 1, values, target);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
