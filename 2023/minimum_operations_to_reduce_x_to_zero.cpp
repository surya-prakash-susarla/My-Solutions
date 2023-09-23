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
  int minOperations(vector<int>& values, int x) {
    unordered_map<int, int> pre;
    unordered_map<int, int> suf;

    pre[0] = -1;
    suf[0] = values.size();

    {
      int temp = 0;
      for (int i = 0; i < values.size(); i++) {
        temp += values[i];
        if (temp > x)
          break;
        pre[temp] = i;
      }
    }
    {
      int temp = 0;
      for (int i = values.size() - 1; i > -1; i--) {
        temp += values[i];
        if (temp > x)
          break;
        suf[temp] = i;
      }
    }

    int answer = INT_MAX;
    for (auto i : pre) {
      auto it = suf.find(x - i.first);
      if (it != suf.end() and it->second > i.second)
        answer =
            min(answer, (int)((i.second + 1) + (values.size() - it->second)));
    }

    return answer == INT_MAX ? -1 : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
