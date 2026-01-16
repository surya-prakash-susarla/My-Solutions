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
  vector<int> plusOne(vector<int>& input) {
    int carry = 0;
    bool init = true;
    for (int i = input.size() - 1; i > -1; i--) {
      int t = input[i] + carry;
      if (init) {
        t++;
        init = not init;
      }
      carry = t / 10;
      input[i] = t % 10;

      if (carry == 0)
        break;
    }

    if (carry != 0) {
      vector<int> temp = {carry};
      temp.insert(temp.end(), input.begin(), input.end());
      return temp;
    } else {
      return input;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
