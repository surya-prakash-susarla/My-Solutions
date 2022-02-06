#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> sortEvenOdd(vector<int>& nums) {
    typedef vector<int> vint;
    vint even;
    vint odd;
    for (int i = 0; i < nums.size(); i++)
      if (i % 2 == 0)
        even.push_back(nums[i]);
      else
        odd.push_back(nums[i]);
    sort(begin(even), end(even));
    sort(begin(odd), end(odd), greater<int>());

    vint answer;
    int i = 0;
    for (; i < min(even.size(), odd.size()); i++) {
      answer.push_back(even[i]);
      answer.push_back(odd[i]);
    }
    if (i < even.size())
      for (; i < even.size(); i++)
        answer.push_back(even[i]);
    if (i < odd.size())
      for (; i < odd.size(); i++)
        answer.push_back(odd[i]);
    return answer;
  }
};