#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> less;
    vector<int> great;
    int eq = 0;
    for (const int i : nums) {
      if (i < pivot)
        less.push_back(i);
      else if (i > pivot)
        great.push_back(i);
      else
        eq++;
    }

    vector<int> ans = less;
    fill_n(back_inserter(ans), eq, pivot);
    // cout << "repeats inserted" << endl;
    ans.insert(ans.end(), great.begin(), great.end());

    return ans;
  }
};
