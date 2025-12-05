class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& input, int target) {
    int rmax = -1;
    {
      for (int i = 0; i < input.size(); i++) {
        if (input[i][0] > target) {
          rmax = i;
          break;
        }
      }
      if (rmax == -1)
        rmax = input.size();
    }

    int cmax = -1;
    {
      auto it = upper_bound(input[0].begin(), input[0].end(), target);
      if (it == input[0].end())
        cmax = input[0].size();
      else
        cmax = distance(input[0].begin(), it);
    }

    for (int i = 0; i < rmax; i++) {
      auto end_it = next(input[i].begin(), cmax);
      auto it = find(input[i].begin(), end_it, target);
      if (it != end_it) {
        return true;
      }
    }

    return false;
  }
};
