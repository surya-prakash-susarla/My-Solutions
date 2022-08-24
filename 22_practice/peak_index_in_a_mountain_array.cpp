#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  typedef vector<int> vint;
  int peakIndexInMountainArray(vector<int>& arr) {
    return __rec__(arr, 0, arr.size() - 1);
  }

  int __rec__(const vint& values, int start, int end) {
    int mid = (start + end) / 2;

    if (mid == 0)
      return __rec__(values, 1, end);
    if (mid == values.size() - 1)
      return __rec__(values, start, values.size() - 2);

    if (values[mid - 1] < values[mid] and values[mid] > values[mid + 1])
      return mid;

    if (values[mid - 1] > values[mid])
      return __rec__(values, start, mid - 1);

    return __rec__(values, mid + 1, end);
  }
};
