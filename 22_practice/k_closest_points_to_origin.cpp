#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    typedef vector<int> vint;
    sort(points.begin(), points.end(), [](const vint& a, const vint& b) {
      return sqrt(a[0] * a[0] + a[1] * a[1]) < sqrt(b[0] * b[0] + b[1] * b[1]);
    });

    return vector<vint>(points.begin(), points.begin() + k);
  }
};

int main() {
  return 0;
}
