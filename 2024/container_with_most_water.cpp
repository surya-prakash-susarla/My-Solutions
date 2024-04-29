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
  int maxArea(vector<int>& values) {
    int prevbest = -1;
    int answer = -1;

    for (int i = 0; i < values.size(); i++) {
      if (values[i] < prevbest)
        continue;
      prevbest = values[i];

      int currentbest = -1;
      for (int j = values.size() - 1; j > i; j--)
        currentbest = max(currentbest, (j - i) * min(values[i], values[j]));

      answer = max(answer, currentbest);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
