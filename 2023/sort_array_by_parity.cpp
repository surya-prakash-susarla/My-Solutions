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
  vector<int> sortArrayByParity(vector<int>& values) {
    int si = 0;
    int ti = 0;

    for (int i = 0; i < values.size(); i++) {
      if (values[i] % 2) {
        si = i;
        break;
      }
    }

    for (int i = si + 1; i < values.size(); i++) {
      if (values[i] % 2 == 0) {
        swap(values[i], values[si]);
        si++;
      }
    }

    return values;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
