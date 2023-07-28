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
  int findKthLargest(vector<int>& values, int k) {
    priority_queue<int> temp;
    for (int i : values)
      temp.push(i);

    int current = -1;
    while (k-- > 0) {
      current = temp.top();
      temp.pop();
    }

    return current;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
