class Solution {
 public:
  int trap(vector<int>& nums) {
    int total_sum = 0, li = 0, ri = 1, size = nums.size();
    bool fail_upper = false;
    while (li < size and ri < size) {
      int sum = 0;
      while (ri < size and nums[li] > nums[ri]) {
        sum += nums[li] - nums[ri];
        ri += 1;
      }
      if (ri < size) {
        total_sum += sum;
        li = ri;
      } else {
        fail_upper = true;
        break;
      }
      ri = li + 1;
    }
    if (fail_upper) {
      int max_limit = li;
      ri = size - 1;
      int ri2 = ri - 1;
      while (ri > max_limit and ri2 > max_limit) {
        int sum = 0;
        while (ri2 > max_limit and nums[ri2] < nums[ri]) {
          sum += nums[ri] - nums[ri2];
          ri2 -= 1;
        }
        if (ri2 > max_limit) {
          total_sum += sum;
          ri = ri2;
        } else {
          total_sum += sum;
          break;
        }
        ri2 = ri - 1;
      }
    }
    return total_sum;
  }
};