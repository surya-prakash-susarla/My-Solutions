#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& values) {
    int rotate = 0;
    for (int i = 1; i < values.size(); i++) {
      if (values[i] > values[i - 1])
        rotate = i;
      else
        break;
    }

    return rotate == values.size() - 1 ? values[0] : values[rotate + 1];
  }
};

int main() {
  return 0;
}
