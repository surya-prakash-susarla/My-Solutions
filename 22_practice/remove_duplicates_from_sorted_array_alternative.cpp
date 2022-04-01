#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int lp = 0;
    int hp = 1;

    while (hp < nums.size()) {
      if (nums[lp] != nums[hp]) {
        lp++;
        swap(nums[lp], nums[hp]);
      }
      hp++;
    }

    return lp + 1;
  }
};