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
  int firstMissingPositive(vector<int>& values) {
    for (int i = 0; i < values.size(); i++) {
      if (values[i] <= 0 or values[i] > values.size())
        continue;
      if (values[values[i] - 1] != values[i]) {
        swap(values[values[i] - 1], values[i]);
        i--;
      }
    }
    for (int i = 0; i < values.size(); i++)
      if (values[i] != i + 1)
        return i + 1;
    return values.size() + 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
