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
  int maxWidthOfVerticalArea(vector<vector<int>>& values) {
    sort(values.begin(), values.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] == b[0])
             return a[1] < b[1];
           return a[0] < b[0];
         });

    int answer = INT_MIN;
    for (int i = 1; i < values.size(); i++) {
      answer = max(answer, values[i][0] - values[i - 1][0]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
