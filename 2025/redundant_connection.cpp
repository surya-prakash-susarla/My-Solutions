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
  typedef vector<bool> vbool;
  typedef vector<vbool> vvbool;

  bool are_connected(const int source,
                     const int target,
                     const int parent,
                     const vvbool& cons) {
    if (source == target) {
      return true;
    }

    bool answer = false;
    for (int i = 0; i < cons.size(); i++) {
      if (cons[source][i] and i != parent and
          are_connected(i, target, source, cons)) {
        answer = true;
        break;
      }
    }

    return answer;
  }

  vector<int> findRedundantConnection(vector<vector<int>>& input) {
    vvbool cons(input.size() + 1, vbool(input.size() + 1, false));

    for (auto& i : input) {
      if (are_connected(i[0], i[1], -1, cons)) {
        return i;
      }

      cons[i[0]][i[1]] = true;
      cons[i[1]][i[0]] = true;
    }

    return {};
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
