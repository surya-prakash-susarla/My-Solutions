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
  bool isZeroArray(vector<int>& input, vector<vector<int>>& values) {
    vector<int> temp(input.size(), 0);

    for (auto i : values) {
      temp[i[0]]++;
      if (i[1] < input.size() - 1)
        temp[i[1] + 1]--;
    }

    int current = 0;

    for (int i = 0; i < input.size(); i++) {
      current += temp[i];
      if (input[i] > current) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
