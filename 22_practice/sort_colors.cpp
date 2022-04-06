#include <bits/stdc++.h>

using namespace std;

/* Test Cases
[2,0,2,1,1,0]
[2,0,1]
[0,0,0]
[1]
[2,2,2,2,2,2,2,2,2,2,2,0]
*/

class Solution {
 public:
  void sortColors(vector<int>& input) {
    const int size = input.size();

    int lp = -1;
    int rp = -1;

    while (lp + 1 < size and input[++lp] == 0)
      ;
    lp--;
    rp = lp + 2;

    while (rp < size) {
      if (input[rp] == 0)
        swap(input[++lp], input[rp]);

      rp++;
    }

    while (lp < size - 1 and input[++lp] == 1)
      ;
    lp--;
    rp = lp + 2;

    while (rp < size) {
      if (input[rp] == 1)
        swap(input[++lp], input[rp]);

      rp++;
    }

    return;
  }
};
