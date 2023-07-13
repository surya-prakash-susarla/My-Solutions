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
  int maxMoves(vector<vector<int>>& input) {
    int m = input.size();
    int n = input[0].size();

    vector<int> memo(m, 1);

    auto get_greatest = [&](int i, int j) -> int {
      int current_value = input[i][j];

      // cout << "starting check" << endl;

      int bg =
          i - 1 > -1 and current_value < input[i - 1][j + 1] ? memo[i - 1] : 0;
      int cg = current_value < input[i][j + 1] ? memo[i] : 0;
      int fg =
          i + 1 < m and current_value < input[i + 1][j + 1] ? memo[i + 1] : 0;

      // cout << "check done" << endl;

      return max({bg, cg, fg});
    };

    for (int i = n - 2; i > -1; i--) {
      // cout << "current value of memo : " << endl;
      // for ( int i : memo )    cout << i << " ";
      // cout << endl;

      vector<int> current(m, 1);
      for (int j = 0; j < m; j++) {
        // cout << "r, c: " << j << " " << i << endl;
        current[j] += get_greatest(j, i);
        // cout << "assignment done" << endl;
      }

      // cout << "values of current : " << endl;
      // for ( int i : current ) cout << i << " ";
      // cout << endl;

      swap(current, memo);
    }

    return (*max_element(memo.begin(), memo.end())) - 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
