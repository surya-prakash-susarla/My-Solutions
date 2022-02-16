#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int answer = 0;
    unordered_map<int, int> reqs;

    int presum = 0;
    reqs[k] = 1;

    for (int i = 0; i < nums.size(); i++) {
      presum += nums[i];
      answer += reqs[presum];
      reqs[k + presum]++;
    }

    return answer;
  }
};
