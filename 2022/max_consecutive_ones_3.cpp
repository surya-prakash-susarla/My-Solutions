#include <bits/stdc++.h>

using namespace std;

/*
Test Cases
[1,1,1,0,0,0,1,1,1,1,0]
2
[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
3
[0,0,0,0,0,0,0,0,0,0]
4
[1]
1
[0]
1
[1,1,1,1,1,0,0,0,0,0,0]
3
*/

class Solution {
 public:
  int longestOnes(vector<int>& input, int k) {
    int maxlen = 0;
    int left = 0;

    int clen = 0;
    int use = 0;

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == 1) {
        clen++;
      } else {
        if (use < k) {
          use++;
          clen++;
        } else {
          while (use >= k) {
            if (input[left] == 0)
              use--;
            clen--;
            left++;
          }
          clen++;
          use++;
        }
      }
      maxlen = max(maxlen, clen);
    }

    return maxlen;
  }
};