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
  int findPeakElement(vector<int>& values) {
    int start = 0;
    int end = values.size() - 1;
    if (start == end)
      return 0;
    if (values[start] > values[start + 1])
      return start;
    if (values[end - 1] < values[end])
      return end;
    start++;
    end--;

    while (start <= end) {
      int mid = (start + end) / 2;
      if (values[mid] > values[mid - 1] and values[mid] > values[mid + 1])
        return mid;
      if (values[mid - 1] > values[mid]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
