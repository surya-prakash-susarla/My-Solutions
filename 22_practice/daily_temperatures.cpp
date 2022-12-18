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
  vector<int> dailyTemperatures(vector<int>& values) {
    vector<int> answer(values.size(), 0);

    map<int, int> temp;
    for (int i = values.size() - 1; i > -1; i--) {
      auto it = temp.upper_bound(values[i]);
      if (it != temp.end()) {
        int temp1 = it->second;
        while (it != temp.end()) {
          temp1 = min(temp1, it->second);
          it = next(it, 1);
        }
        answer[i] = temp1 - i;
      }
      temp[values[i]] = i;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
