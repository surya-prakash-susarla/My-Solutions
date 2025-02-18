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
  void sortColors(vector<int>& input) {
    map<int, int> counts;
    for (int i : input)
      counts[i]++;

    int ind = 0;
    for (auto i : counts) {
      for (int j = 0; j < i.second; j++)
        input[ind++] = i.first;
    }

    return;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
