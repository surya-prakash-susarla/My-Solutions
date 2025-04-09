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
  int minOperations(vector<int>& input, int k) {
    set<int> values;
    for (int i : input)
      values.insert(i);

    if (*values.begin() < k)
      return -1;

    return *values.begin() == k ? (values.size() - 1) : values.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
