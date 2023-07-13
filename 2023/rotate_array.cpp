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
  void rotate(vector<int>& values, int k) {
    deque<int> q(values.begin(), values.end());

    while (k-- > 0) {
      q.push_front(q.back());
      q.pop_back();
    }

    vector<int> temp;
    while (not q.empty()) {
      temp.push_back(q.front());
      q.pop_front();
    }

    values = temp;

    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
