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
  int search(vector<int>& values, int target) {
    int left = 0;
    int right = values.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (values[mid] == target)
        return mid;
      if (values[left] <= values[mid]) {
        if (target >= values[left] and target <= values[mid]) {
          right = mid - 1;
          continue;
        }
      } else {
        if (target >= values[left] or target <= values[mid]) {
          right = mid - 1;
          continue;
        }
      }
      if (values[right] >= values[mid]) {
        if (target >= values[mid] and target <= values[right]) {
          left = mid + 1;
          continue;
        }
      } else {
        if (target >= values[mid] or target <= values[right]) {
          left = mid + 1;
          continue;
        }
      }
      break;
    }
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
