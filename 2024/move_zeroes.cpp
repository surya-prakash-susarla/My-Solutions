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
  void moveZeroes(vector<int>& values) {
    for (int i = 0; i < values.size(); i++) {
      if (values[i] == 0) {
        int j = -1;
        for (int k = i + 1; k < values.size(); k++) {
          if (values[k] != 0) {
            j = k;
            break;
          }
        }
        if (j == -1)
          return;
        swap(values[i], values[j]);
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
