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
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    priority_queue<int, vector<int>, greater<int>> values;

    for (int i = 0; i < dist.size(); i++) {
      values.push(ceil(float(dist[i]) / speed[i]));
    }

    int answer = 0;
    int t = 1;

    while (not values.empty()) {
      int current = values.top();
      if (current < t)
        break;
      t++;
      answer++;
      values.pop();
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
