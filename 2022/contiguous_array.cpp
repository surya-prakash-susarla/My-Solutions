#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> values;
    int maxsize = 0;
    int sum = 0;
    values[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i] == 0 ? -1 : 1;
      auto it = values.find(sum);
      if (it != values.end()) {
        maxsize = max(maxsize, i - it->second);
      } else {
        values[sum] = i;
      }
    }
    return maxsize;
  }
};