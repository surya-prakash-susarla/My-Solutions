#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> answer;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
      if (i == nums.size() - 1 or nums[i] != nums[i + 1])
        answer.push_back(nums[i]);
      else
        i += 1;
    return answer;
  }
};