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
  int fill(int i, int j, vector<vector<int>>& input) {
    if (i < 0 or i >= input.size() or j < 0 or j >= input[0].size())
      return 0;

    if (input[i][j] == 0)
      return 0;

    int answer = input[i][j];
    input[i][j] = 0;

    answer += fill(i - 1, j, input);
    answer += fill(i + 1, j, input);
    answer += fill(i, j - 1, input);
    answer += fill(i, j + 1, input);

    return answer;
  }

  int findMaxFish(vector<vector<int>>& input) {
    int answer = INT_MIN;

    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[0].size(); j++) {
        answer = max(answer, fill(i, j, input));
      }
    }

    return answer == INT_MIN ? 0 : answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
