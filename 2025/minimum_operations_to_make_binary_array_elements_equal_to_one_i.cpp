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
  int minOperations(vector<int>& input) {
    int counter = 0;
    for (int i = 0; i < input.size(); i++) {
      if (input[i] == 0) {
        for (int j = 0; j < 3; j++) {
          if (i + j >= input.size())
            return -1;
          input[i + j] = (input[i + j] == 0 ? 1 : 0);
        }
        counter++;
      }
    }
    return counter;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
