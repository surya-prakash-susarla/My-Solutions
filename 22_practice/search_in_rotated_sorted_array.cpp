#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int search(vector<int>& values, int target) {
    int rotate = 0;

    for (int i = 1; i < values.size(); i++) {
      if (values[i] < values[i - 1])
        break;
      else
        rotate = i;
    }

    bool found = false;

    if (rotate >= 0 and values[0] <= target and values[rotate] >= target) {
      auto it =
          lower_bound(values.begin(), next(values.begin(), rotate + 1), target);
      return it == values.end() or *it > target ? -1 : it - values.begin();
    }

    if (rotate + 1 < values.size() and values[rotate + 1] <= target and
        *values.rbegin() >= target) {
      auto it =
          lower_bound(next(values.begin(), rotate + 1), values.end(), target);
      return it == values.end() or *it > target ? -1 : it - values.begin();
    }

    return -1;
  }
};

int main() {
  return 0;
}
