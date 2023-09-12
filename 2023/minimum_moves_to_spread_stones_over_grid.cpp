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
  int __rec__(vector<vector<int>>& values) {
    bool requires_filling = false;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (values[i][j] == 0) {
          requires_filling = true;
          break;
        }
    if (not requires_filling)
      return 0;

    int answer = INT_MAX;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (values[i][j] == 0) {
          for (int ti = 0; ti < 3; ti++) {
            for (int tj = 0; tj < 3; tj++) {
              if (values[ti][tj] > 1) {
                int temp = abs(ti - i) + abs(tj - j);
                values[ti][tj]--;
                values[i][j]++;
                int dist = temp + __rec__(values);
                values[ti][tj]++;
                values[i][j]--;
                answer = min(answer, dist);
              }
            }
          }
        }
      }
    }

    return answer;
  }

  int minimumMoves(vector<vector<int>>& grid) { return __rec__(grid); }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
