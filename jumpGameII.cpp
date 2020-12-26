class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1)
      return 0;
    map<int, int> values;
    values.insert(make_pair(0, 0));
    int highest_index = 0;
    while (not values.empty()) {
      pair<int, int> first = *(values.begin());
      values.erase(first.first);
      for (int i = highest_index + 1; i <= first.first + nums[first.first]; i++)
        if (i >= nums.size() - 1)
          return first.second + 1;
        else
          values.insert(make_pair(i, first.second + 1));
      highest_index = values.rbegin()->first;
    }
    return -1;
  }
};