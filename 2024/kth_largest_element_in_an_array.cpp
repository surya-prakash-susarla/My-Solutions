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
  int findKthLargest(vector<int>& nums, int k) {
    vector<int> left;
    vector<int> mid;
    vector<int> right;

    int x = nums[nums.size() / 2];

    for (int i : nums) {
      if (i > x)
        left.push_back(i);
      else if (i == x)
        mid.push_back(i);
      else
        right.push_back(i);
    }

    if (k <= left.size())
      return findKthLargest(left, k);
    else if (k > (left.size() + mid.size()))
      return findKthLargest(right, k - (left.size() + mid.size()));
    else
      return mid[0];
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
