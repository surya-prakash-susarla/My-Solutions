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
  bool doesValidArrayExist(vector<int>& values) {
    int n = values.size();

    vector<int> solution(n);

    solution[0] = 0;

    for (int i = 0; i < n - 1; i++) {
      if (values[i] == 0)
        solution[i + 1] = solution[i];
      else
        solution[i + 1] = (solution[i] == 0 ? 1 : 0);
    }

    return values[n - 1] == 1 ? (solution[n - 1] != solution[0])
                              : (solution[n - 1] == solution[0]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
