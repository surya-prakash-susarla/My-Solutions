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
  int solve(int left, int right, const vector<int>& values) {
    if (left > right)
      return INT_MIN;
    if (left == right)
      return values[left];

    int neg = 0;
    for (int i = left; i <= right; i++) {
      if (values[i] == 0) {
        return max(
            {solve(left, i - 1, values), solve(i + 1, right, values), 0});
      } else if (values[i] < 0) {
        neg++;
      }
    }

    if (neg % 2 == 0) {
      int answer = 1;
      for (int i = left; i <= right; i++)
        answer *= values[i];
      return answer;
    } else {
      // remove first neg.
      int ind = -1;
      for (int i = left; i <= right; i++) {
        if (values[i] < 0 and ind == -1) {
          ind = i;
          break;
        }
      }
      int lvalue = 1;
      if (ind != -1)
        for (int i = ind + 1; i <= right; i++)
          lvalue *= values[i];
      else
        lvalue = INT_MIN;

      // cout << "left ind : " << ind << endl;

      // remove right neg.
      ind = -1;
      for (int i = right; i >= left; i--) {
        if (values[i] < 0 and ind == -1) {
          ind = i;
          break;
        }
      }
      int rvalue = 1;
      if (ind != -1)
        for (int i = ind - 1; i >= left; i--)
          rvalue *= values[i];
      else
        rvalue = INT_MIN;

      // cout << "right ind : " << ind << endl;

      return max(lvalue, rvalue);
    }
  }

  int maxProduct(vector<int>& values) {
    return solve(0, values.size() - 1, values);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
