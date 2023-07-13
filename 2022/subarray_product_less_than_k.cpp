#include <bits/stdc++.h>

using namespace std;

/*
[10,5,2,6]
100
[1,2,3]
0
[3,5,6,7,8,100,200,300,400,500,100,1000,1000,1000]
500000
[1,1,1,1,1,1]
500
[500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500]
0
[10,9,10,4,3,8,3,3,6,2,10,10,9,3]
19
*/

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& input, int target) {
    const int size = input.size();

    int left = 0;
    int right = 0;

    int answer = 0;

    int csum = 1;
    while (right < size and csum * input[right] < target)
      csum *= input[right++];

    answer = ((right - left) * (right - left + 1)) / 2;

    while (left <= right and right < size) {
      csum *= input[right];

      while (left <= right and csum >= target)
        csum /= input[left++];

      if (left == right and input[left] >= target)
        break;

      int ta = ((right + 1 - left) * (right + 2 - left)) / 2;
      int pa = ((right - left) * (right - left + 1)) / 2;

      answer += (ta - pa);

      right++;
    }

    return answer;
  }
};
