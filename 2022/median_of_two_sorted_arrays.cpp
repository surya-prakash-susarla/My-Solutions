#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  inline int getNextValue(int& left,
                          int& right,
                          const vector<int>& a,
                          const vector<int>& b) {
    if (left >= a.size())
      return b[right++];
    else if (right >= b.size())
      return a[left++];
    else if (a[left] <= b[right]) {
      return a[left++];
    } else {
      return b[right++];
    }
  }

  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int mid_position = (a.size() + b.size()) / 2;

    int left = 0;
    int right = 0;

    int prev_value = -1;
    int mid_value = -1;

    for (int cpos = 0; cpos <= mid_position; cpos++) {
      prev_value = mid_value;
      mid_value = getNextValue(left, right, a, b);
    }

    if ((a.size() + b.size()) % 2 == 0)
      return (double)(prev_value + mid_value) / 2;
    return mid_value;
  }
};

int main() {
  return 0;
}
