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
  int peakIndexInMountainArray(vector<int>& input) {
    int left = 1;
    int right = input.size() - 2;

    while (left <= right) {
      int mid = (left + right) / 2;
      if (input[mid - 1] < input[mid] and input[mid] > input[mid + 1]) {
        return mid;
      } else if (input[mid - 1] > input[mid] and input[mid] > input[mid + 1]) {
        right = mid - 1;
      } else if (input[mid - 1] < input[mid] and input[mid] < input[mid + 1]) {
        left = mid + 1;
      } else {
        // cout << "some unknown case happened here, plateau? , mid val : " <<
        // input[mid] << endl;
      }
    }

    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
