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
  int maximalSquare(vector<vector<char>>& input) {
    int n = input.size();
    int m = input[0].size();
    vector<vector<int>> memo(n, vector<int>(m, 0));
    int answer = 0;

    for (int i = n - 1; i > -1; i--) {
      for (int j = m - 1; j > -1; j--) {
        const int right = j + 1 < m ? memo[i][j + 1] : 0;
        const int down = i + 1 < n ? memo[i + 1][j] : 0;
        const int diag = (i + 1 < n and j + 1 < m) ? memo[i + 1][j + 1] : 0;
        memo[i][j] = (input[i][j] == '1' ? 1 + min({right, down, diag}) : 0);
        answer = max(answer, memo[i][j]);
      }
    }

    return answer * answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
