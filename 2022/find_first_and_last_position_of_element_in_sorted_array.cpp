#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> answer = __calc__(0, nums.size() - 1, target, nums);
    if (not answer.empty())
      return answer;
    return {-1, -1};
  }

  typedef vector<int> vint;

  vint __calc__(int start, int end, int target, const vint values) {
    if (start > end)
      return {};

    if (start == end) {
      if (values[start] == target)
        return {start, start};
      return {};
    }

    int mid_index = (start + end) / 2;
    int mid_value = values[mid_index];

    if (mid_value == target) {
      int left = mid_index;
      while (left - 1 > -1 and values[left - 1] == target)
        left--;
      int right = mid_index;
      while (right + 1 < values.size() and values[right + 1] == target)
        right++;
      return {left, right};
    }

    if (mid_value < target)
      return __calc__(mid_index + 1, end, target, values);

    return __calc__(start, mid_index - 1, target, values);
  }
};