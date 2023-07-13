#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> answer = {{}};
    for (int i : nums) {
      for (int j = answer.size() - 1; j > -1; j--) {
        vector<int> temp(answer[j]);
        temp.push_back(i);
        answer.emplace_back(move(temp));
      }
    }
    return answer;
  }
};