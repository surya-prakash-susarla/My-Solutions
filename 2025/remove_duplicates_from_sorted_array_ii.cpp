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
  int removeDuplicates(vector<int>& input) {
    int prev_element = INT_MIN;
    int prev_count = 0;

    for (int& i : input) {
      if (i == prev_element) {
        prev_count++;
        if (prev_count > 2) {
          i = INT_MAX;
        }
      } else {
        prev_element = i;
        prev_count = 1;
      }
    }

    sort(input.begin(), input.end());

    int k = 0;
    for (int i : input) {
      if (i == INT_MAX)
        break;
      k++;
    }

    return k;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
