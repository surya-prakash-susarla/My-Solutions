#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> final_answer;

  void calc(vector<int> values, vector<int> answer) {
    if (values.size() == 0) {
      final_answer.push_back(answer);
      return;
    }
    for (int i = 0; i < values.size(); i++) {
      auto temp = values, temp_answer = answer;
      temp_answer.push_back(values[i]);
      temp.erase(temp.begin() + i);
      calc(temp, temp_answer);
    }
    return;
  }

  vector<vector<int>> permute(vector<int>& nums) {
    calc(nums, vector<int>());
    return final_answer;
  }
};