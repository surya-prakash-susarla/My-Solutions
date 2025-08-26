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
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    auto calc = [](int a, int b) -> double {
      return (double)sqrt((a * a) + (b * b));
    };

    double maxval = 0;
    int area = 0;

    for (auto i : dimensions) {
      double current = calc(i[0], i[1]);
      if (current == maxval) {
        if (area < i[0] * i[1]) {
          maxval = current;
          area = i[0] * i[1];
        }
      } else if (current > maxval) {
        maxval = current;
        area = i[0] * i[1];
      }
    }

    return area;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
