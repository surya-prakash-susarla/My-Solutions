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
      // cout << "left : " << left << " , right : " << right << endl;
      int mid = (left + right) / 2;

      if (values[mid] == target)
        return mid;

      if (values[left] <= values[mid]) {
        // regular left
        if (target >= values[left] and target <= values[mid]) {
          right = mid - 1;
          // cout << "right regular from left updated to : " << right << endl;
          continue;
        }
      } else {
        // irregular left
        if (target >= values[left] or target <= values[mid]) {
          right = mid - 1;
          // cout << "right irregular from left updated to : " << right << endl;
          continue;
        }
      }
      if (values[right] >= values[mid]) {
        // regular right
        if (target >= values[mid] and target <= values[right]) {
          left = mid + 1;
          // cout << "left regular from right updated to : " << left << endl;
          continue;
        }
      } else {
        // irregular right
        if (target >= values[mid] or target <= values[right]) {
          left = mid + 1;
          // cout << "left irregular from right updated to : " << left << endl;
          continue;
        }
      }

      // if ( left == t1 and right == t2 ) {
      //     cout << "breaking cause no index change : " << endl;
      //     break;
      // }

      // cout << "values of left for next iteration : " << left << endl;
      // cout << "values of right for next iteration : " << right << endl;

      break;
    }
    // cout << "stepped out of the block" << endl;
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
