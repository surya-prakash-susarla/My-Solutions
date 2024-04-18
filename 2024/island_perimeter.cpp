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
  typedef vector<vint> vvint;

  inline int get(int i, int j, const vvint& input) {
    int answer = 0;
    if (i - 1 < 0 or input[i - 1][j] == 0)
      answer++;
    if (j - 1 < 0 or input[i][j - 1] == 0)
      answer++;
    if (i + 1 >= input.size() or input[i + 1][j] == 0)
      answer++;
    if (j + 1 >= input[i].size() or input[i][j + 1] == 0)
      answer++;
    return answer;
  }

  int islandPerimeter(vector<vector<int>>& input) {
    int answer = 0;

    for (int i = 0; i < input.size(); i++)
      for (int j = 0; j < input[i].size(); j++)
        if (input[i][j] == 1)
          answer += get(i, j, input);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
