#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

class Solution {
 public:
  int move(int& left,
           int& right,
           const vector<int>& values_1,
           const vector<int>& values_2) {
    if (left < values_1.size() and right < values_2.size()) {
      if (values_1[left] < values_2[right])
        return values_1[left++];
      else
        return values_2[right++];
    } else if (left < values_1.size()) {
      return values_1[left++];
    } else {
      return values_2[right++];
    }
  }

  double findMedianSortedArrays(vector<int>& values_1, vector<int>& values_2) {
    int left = 0;
    int right = 0;

    int req = (values_1.size() + values_2.size()) / 2;

    int last_known = -1;
    while (req) {
      last_known = move(left, right, values_1, values_2);
      req--;
    }

    if ((values_1.size() + values_2.size()) % 2 == 0) {
      int val1 = move(left, right, values_1, values_2);
      return (double)(last_known + val1) / 2;
    } else {
      return (double)(move(left, right, values_1, values_2));
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
