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
  int snakesAndLadders(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> cons(n * n + 1, -1);
    {
      bool dir = true;
      int ind = 1;
      for (int i = n - 1; i > -1; i--, dir = not dir) {
        if (dir) {
          for (int j = 0; j < n; j++, ind++)
            cons[ind] = grid[i][j];
        } else {
          for (int j = n - 1; j > -1; j--, ind++)
            cons[ind] = grid[i][j];
        }
      }
    }

    {
      int maxvalue = n * n;
      int steps = 0;
      vector<bool> visited(maxvalue + 1, false);
      queue<int> values;

      values.push(1);

      while (not values.empty()) {
        queue<int> next;
        steps++;
        while (not values.empty()) {
          int top = values.front();
          values.pop();
          if (visited[top])
            continue;
          visited[top] = true;
          if (top == maxvalue) {
            return steps - 1;
          }
          for (int i = 1; i <= 6; i++) {
            int next_ind = top + i;
            if (next_ind > maxvalue)
              break;
            if (cons[next_ind] == -1) {
              if (not visited[next_ind])
                next.push(next_ind);
            } else {
              if (not visited[cons[next_ind]])
                next.push(cons[next_ind]);
            }
          }
        }
        swap(next, values);
      }

      return -1;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
