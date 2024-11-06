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
  bool canSortArray(vector<int>& input) {
    for (int x = 0; x < input.size(); x++) {
      for (int i = 0; i < input.size() - 1; i++) {
        if (input[i] > input[i + 1]) {
          if ((bitset<32>(input[i])).count() !=
              (bitset<32>(input[i + 1])).count())
            return false;
          swap(input[i], input[i + 1]);
        }
      }
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
