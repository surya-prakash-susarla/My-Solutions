#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& nums1,
                   vector<int>& nums2,
                   vector<int>& nums3,
                   vector<int>& nums4) {
    typedef unordered_map<int, int> um;

    um one;
    for (int i : nums1)
      for (int j : nums2)
        one[i + j]++;

    int count = 0;
    for (int i : nums3)
      for (int j : nums4)
        count += one[(0 - i - j)];

    return count;
  }
};
