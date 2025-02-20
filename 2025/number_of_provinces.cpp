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
  vector<bool> covered;
  vector<vector<int>> cons;

  void __rec__(int i) {
    if (covered[i])
      return;

    covered[i] = true;
    for (int j = 0; j < cons.size(); j++)
      if (cons[i][j])
        __rec__(j);

    return;
  }

  int findCircleNum(vector<vector<int>>& cons) {
    covered = vector<bool>(cons.size(), false);
    this->cons = cons;

    int answer = 0;

    for (int i = 0; i < cons.size(); i++) {
      if (not covered[i]) {
        answer++;
        __rec__(i);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
