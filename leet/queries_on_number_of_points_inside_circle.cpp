#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

// Problem:

typedef long long int llint;
typedef long double ldouble;

using namespace std;

class Solution {
 public:
  vector<int> countPoints(vector<vector<int>>& points,
                          vector<vector<int>>& queries) {
    vector<int> answers;

    for (const vector<int>& q : queries) {
      const int sqt = q[2] * q[2];
      int answer = 0;
      for (const vector<int>& p : points) {
        if (p[0] == q[0]) {
          if (abs(p[1] - q[1]) <= q[2])
            answer++;
        } else if (p[1] == q[1]) {
          if (abs(p[0] - q[0]) <= q[2])
            answer++;
        } else {
          const int x = (p[0] - q[0]);
          const int y = (p[1] - q[1]);
          if (x * x + y * y <= sqt)
            answer++;
        }
      }
      answers.push_back(answer);
    }
    return answers;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
