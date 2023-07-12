#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& input) {
    for (int i = 0; i < input.size(); i += 2)
      if (i == input.size() - 1 or input[i] != input[i + 1])
        return input[i];
    return -1;
  }
};