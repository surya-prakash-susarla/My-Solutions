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
  int majorityElement(vector<int>& values) {
    int element = -1;
    int count = 0;
    for (int i : values) {
      if (count == 0) {
        element = i;
        count = 1;
      } else if (i == element)
        count++;
      else
        count--;
    }
    count = 0;
    for (int i : values)
      if (i == element)
        count++;
    return count >= (values.size() / 2) ? element : -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
