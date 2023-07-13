#include <bits/stdc++.h>

using namespace std;

/* Test cases
[-1,2,1,-4]
1
[0,0,0]
1
[2,2,2,2,3,3,3,3,1,1,1,1]
6
[-1,-2,-3,-4,-5,-6,-7,-8,-9,0,0,0,0,0,0,0,0,0,0]
-8
[0,1,2]
10
*/

class Solution {
 public:
  int threeSumClosest(vector<int>& input, int target) {
    sort(input.begin(), input.end());

    const int maxvalue = numeric_limits<int>::max();
    const int size = input.size();
    int cdiff = maxvalue;
    int answer = maxvalue;

    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        int csum = input[i] + input[j];
        int req = target - csum;

        auto it = lower_bound(next(input.begin(), j + 1), input.end(), req);

        int ud = maxvalue;
        if (it != input.end()) {
          if (*it == req)
            return target;
          csum = input[i] + input[j] + *it;
          if (abs(target - csum) < cdiff) {
            cdiff = abs(target - csum);
            answer = csum;
          }
        }

        int ld = maxvalue;
        if (it != input.begin() and it - input.begin() - 1 != j) {
          csum = input[i] + input[j] + *prev(it);
          if (abs(target - csum) < cdiff) {
            cdiff = abs(target - csum);
            answer = csum;
          }
        }
      }
    }

    return answer;
  }
};
