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
    int m = input.size();
    int n = input[0].size();

    vector<vector<int>> values(m + 1, vector<int>(n + 1));

    int answer = 0;

    for (int i = m - 1; i > -1; i--) {
      for (int j = n - 1; j > -1; j--) {
        if (input[i][j] == '0') {
          values[i][j] = 0;
        } else {
          values[i][j] =
              min({values[i + 1][j], values[i + 1][j + 1], values[i][j + 1]}) +
              1;
          answer = max(answer, values[i][j]);
        }
      }
    }

    return answer * answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
