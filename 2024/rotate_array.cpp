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
  void rotate(vector<int>& values, int k) {
    const int n = values.size();
    k %= n;
    reverse(values.begin(), values.begin() + (n - k));
    reverse(values.begin() + (n - k), values.end());
    reverse(values.begin(), values.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
