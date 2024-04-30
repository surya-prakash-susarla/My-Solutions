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
  vector<int> spiralOrder(vector<vector<int>>& values) {
    int r1 = 0;
    int r2 = values.size() - 1;
    int c1 = 0;
    int c2 = values[0].size() - 1;

    vector<int> answer;

    while (r1 <= r2 and c1 <= c2) {
      if (r1 == r2 and c1 == c2) {
        answer.push_back(values[r1][c1]);
      } else if (r1 == r2) {
        for (int i = c1; i <= c2; i++)
          answer.push_back(values[r1][i]);
      } else if (c1 == c2) {
        for (int i = r1; i <= r2; i++)
          answer.push_back(values[i][c1]);
      } else {
        for (int j = c1; j < c2; j++)
          answer.push_back(values[r1][j]);
        for (int i = r1; i < r2; i++)
          answer.push_back(values[i][c2]);
        for (int i = c2; i > c1; i--)
          answer.push_back(values[r2][i]);
        for (int i = r2; i > r1; i--)
          answer.push_back(values[i][c1]);
      }

      r1++;
      r2--;
      c1++;
      c2--;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
