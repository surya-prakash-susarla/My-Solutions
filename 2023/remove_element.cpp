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
  int removeElement(vector<int>& values, int val) {
    const int maxvalue = numeric_limits<int>::max();
    int count = 0;
    for (int& i : values)
      if (i == val) {
        i = maxvalue;
        count++;
      }
    sort(values.begin(), values.end());
    return values.size() - count;
  }
};
int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
