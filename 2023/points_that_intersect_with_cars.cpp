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
  int numberOfPoints(vector<vector<int>>& values) {
    vector<bool> temp(100, false);
    int answer = 0;
    for (auto i : values) {
      for (int j = i[0]; j <= i[1]; j++) {
        if (not temp[j - 1]) {
          answer++;
        }
        temp[j - 1] = true;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
