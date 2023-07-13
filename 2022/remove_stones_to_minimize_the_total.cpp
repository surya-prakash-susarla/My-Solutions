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
  int minStoneSum(vector<int>& temp, int k) {
    priority_queue<int> values;
    int total_sum = 0;
    for (int i : temp) {
      values.push(i);
      total_sum += i;
    }

    // cout << "initial total sum : " << total_sum << endl;

    while (k--) {
      int top = values.top();
      values.pop();
      int removed = (top / 2);

      // cout << "curently picked value : " << top << endl;
      // cout << "contents removed : " << removed << endl;

      total_sum -= removed;
      top -= removed;

      // cout << "updated value : " << top << endl;
      // cout << "total sum : " << total_sum << endl;

      values.push(top);
    }
    return total_sum;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
