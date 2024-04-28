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
  vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<int> reqs(n, 0);
    map<int, list<int>> deps;

    for (auto i : prerequisites) {
      deps[i[1]].push_back(i[0]);
      reqs[i[0]]++;
    }

    vector<int> answer;
    while (true) {
      vector<int> current_set;
      for (int i = 0; i < n; i++)
        if (reqs[i] == 0) {
          current_set.push_back(i);
          reqs[i] = -1;
        }
      if (current_set.empty())
        break;
      answer.insert(answer.end(), current_set.begin(), current_set.end());
      for (auto i : current_set)
        for (auto j : deps[i])
          reqs[j]--;
    }

    for (int i = 0; i < n; i++)
      if (reqs[i] > 0)
        return {};

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
