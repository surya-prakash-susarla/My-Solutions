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
  priority_queue<int> values;

  int k;

  void insert(int x) {
    if (values.size() == k) {
      if (values.top() > x) {
        values.pop();
        values.push(x);
      } else {
        return;
      }
    } else {
      values.push(x);
    }
  }

  int kthSmallest(vector<vector<int>>& input, int k) {
    this->k = k;
    for (auto i : input) {
      for (auto j : i) {
        insert(j);
      }
    }

    return values.top();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
