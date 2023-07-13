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
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> values;
    for (int i : stones)
      values.push(i);

    for (; values.size() > 1;) {
      int top = values.top();
      values.pop();
      int stop = values.top();
      values.pop();

      if (top == stop)
        continue;
      else {
        if (top > stop) {
          values.push(top - stop);
        } else {
          values.push(stop - top);
        }
      }
    }

    return values.size() == 1 ? values.top() : 0;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
