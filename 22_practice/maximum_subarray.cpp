#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& values) {
    int maxvalue = *values.rbegin();
    int current_value = *values.rbegin();

    for (int i = values.size() - 2; i > -1; i--) {
      current_value = max(values[i], values[i] + current_value);
      maxvalue = max(maxvalue, current_value);
    }

    return maxvalue;
  }
};

int main() {
  return 0;
}
