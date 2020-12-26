#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    vector<bool> values(nums.size(), false);
    for (int i : nums)
      if (not values[i])
        values[i] = true;
      else
        return i;
    return -1;
  }
};