#include <bits/stdc++.h>

using namespace std;

/* Test Cases
[2,6,4,8,10,9,15]
[1,2,3,4]
[1]
[2,1]
[3,2,2]
[4,4,4,4,4,4,3,3,3,3,3,3,2,2,2,2]
[4,4,4,4,3,3,3,3,3,2,2,2,2,5,5,5,5,5,5]
[1,2,4,5,3]
[1,6,2,5,3,4]
[4,7,6,2,10,12,13]
[15,9,12,7,6,8,9,1,16,19,21]
*/

class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    vector<int> input(nums);
    sort(input.begin(), input.end());

    int left = 0;
    for (; left < input.size(); left++)
      if (input[left] != nums[left])
        break;

    if (left == input.size())
      return 0;

    int right = input.size() - 1;
    for (; right > -1; right--)
      if (input[right] != nums[right])
        break;

    return (right - left) + 1;
  }
};
