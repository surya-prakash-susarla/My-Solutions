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
  typedef vector<int> vint;
  typedef pair<vint, vint> pvint;

  int minReorder(int n, vector<vector<int>>& input) {
    unordered_map<int, pvint> cons;

    for (const vint& i : input) {
      cons[i[0]].first.push_back(i[1]);
      cons[i[1]].second.push_back(i[0]);
    }

    int answer = 0;

    queue<int> current;
    unordered_map<int, bool> covered;
    current.push(0);

    while (not current.empty()) {
      queue<int> next;

      while (not current.empty()) {
        int node = current.front();
        current.pop();
        covered[node] = true;
        const pvint& con = cons[node];
        for (int i : con.first)
          if (not covered[i]) {
            answer++;
            next.push(i);
          }
        for (int i : con.second)
          if (not covered[i])
            next.push(i);
      }

      swap(next, current);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
