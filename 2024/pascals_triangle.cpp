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
  vector<vector<int>> generate(int n) {
    if (n == 1)
      return {{1}};
    if (n == 2)
      return {{1}, {1, 1}};

    vector<vector<int>> answer;
    answer.push_back({1});
    answer.push_back({1, 1});

    for (int i = 3; i <= n; i++) {
      vector<int> current = {1};
      for (int j = 0; j < i - 2; j++)
        current.push_back(answer[i - 2][j] + answer[i - 2][j + 1]);
      current.push_back(1);
      answer.emplace_back(current);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
