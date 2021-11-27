#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    map<int, set<int>> counter;

    for (const vector<int>& i : logs) {
      counter[i[0]].insert(i[1]);
    }

    vector<int> answer(k, 0);

    for (const pair<int, set<int>>& i : counter) {
      if (i.second.size() <= k) {
        answer[i.second.size() - 1]++;
      }
    }

    return answer;
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
