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
  vector<vector<int>> threeSum(vector<int>& values) {
    set<vector<int>> temp;

    sort(values.begin(), values.end());

    for (int i = 0; i < values.size(); i++) {
      int j = i + 1;
      int k = values.size() - 1;

      while (j < k) {
        int sum = values[i] + values[j] + values[k];
        if (sum == 0) {
          temp.insert({values[i], values[j], values[k]});
          j++;
          k--;
        } else if (sum < 0) {
          j++;
        } else {
          k--;
        }
      }
    }

    return vector<vector<int>>(temp.begin(), temp.end());
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
