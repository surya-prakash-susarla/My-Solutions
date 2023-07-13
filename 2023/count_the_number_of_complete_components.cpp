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
  int countCompleteComponents(int n, vector<vector<int>>& input) {
    vector<vector<bool>> cons(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
      cons[i][i] = true;

    for (auto i : input) {
      cons[i[0]][i[1]] = true;
      cons[i[1]][i[0]] = true;
    }

    vector<bool> covered(n, false);

    function<void(int, vector<int>&)> dfs = [&](int node,
                                                vector<int>& ref) -> void {
      if (covered[node])
        return;
      covered[node] = true;

      ref.push_back(node);

      for (int i = 0; i < n; i++)
        if (cons[node][i])
          dfs(i, ref);

      return;
    };

    int answer = 0;

    int index = -1;
    for (;;) {
      for (int i = 0; i < n; i++)
        if (not covered[i]) {
          index = i;
          break;
        } else {
          index = -1;
        }

      if (index == -1)
        break;

      vector<int> current;

      dfs(index, current);

      bool connected = true;

      for (int i = 0; i < current.size(); i++) {
        for (int j = 0; j < current.size(); j++)
          if (not cons[current[i]][current[j]]) {
            connected = false;
            break;
          }
      }

      if (connected)
        answer++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
