#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, vector<int>> values;

    sort(nums.begin(), nums.end());

    int counter = 1;
    int prev = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == prev) {
        counter++;
      } else {
        values[counter].push_back(prev);
        counter = 1;
        prev = nums[i];
      }
    }

    values[counter].push_back(prev);

    vector<int> answer;
    for (auto it = values.rbegin(); it != values.rend(); it = next(it)) {
      if (it->second.size() <= k) {
        answer.insert(answer.end(), it->second.begin(), it->second.end());
        k -= it->second.size();
      } else {
        answer.insert(answer.end(), it->second.begin(),
                      next(it->second.begin(), k));
        break;
      }
    }

    return answer;
  }
};