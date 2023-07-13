#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> values;
    for (int i = 0; i < nums.size(); i++)
      values[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++) {
      auto it = values.find(target - nums[i]);
      if (it != values.end() and it->second != i)
        return {i, it->second};
    }

    return {};
  }
};
