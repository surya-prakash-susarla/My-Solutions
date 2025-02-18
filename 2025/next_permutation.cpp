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
  void nextPermutation(vector<int>& values) {
    for (int i = values.size() - 1; i > -1; i--) {
      for (int j = values.size() - 1; j > i; j--) {
        if (values[j] > values[i]) {
          // cout << "swapping : " << values[i] << ", " << values[j] << endl;
          swap(values[j], values[i]);
          sort(values.begin() + i + 1, values.end());
          return;
        }
      }
    }

    sort(values.begin(), values.end());
    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
