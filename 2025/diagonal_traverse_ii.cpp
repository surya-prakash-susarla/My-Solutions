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
  vector<int> findDiagonalOrder(vector<vector<int>>& input) {
    typedef vector<int> vint;
    unordered_map<int, vint> values;

    int max_diag = 0;

    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[i].size(); j++) {
        values[i + j].push_back(input[i][j]);
        max_diag = max(max_diag, i + j);
      }
    }

    vint answer;
    for (int i = 0; i <= max_diag; i++) {
      auto ref = values[i];
      answer.insert(answer.end(), ref.rbegin(), ref.rend());
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
