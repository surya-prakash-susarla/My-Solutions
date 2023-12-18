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
  int maxProductDifference(vector<int>& values) {
    sort(values.begin(), values.end());

    int a = values[0];
    int b = values[1];
    int n = values.size();
    int c = values[n - 1];
    int d = values[n - 2];

    return (c * d) - (a * b);
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
