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
  bool is_valid(int index, const string& input_value) {
    return input_value[index] != '0';
  }

  bool is_valid(int index1, int index2, const string& input_value) {
    if (input_value[index1] == '0')
      return false;
    if (input_value[index1] == '2') {
      return input_value[index2] - '0' < 7;
    }
    return input_value[index1] - '0' < 3;
  }

  int numDecodings(string input_value) {
    if (input_value.size() == 0)
      return 0;

    vector<int> values(input_value.size(), 0);
    *values.rbegin() = is_valid(input_value.size() - 1, input_value) ? 1 : 0;
    for (int i = input_value.size() - 2; i > -1; i--) {
      int cvalue = 0;
      if (is_valid(i, input_value)) {
        cvalue += values[i + 1];
      }
      if (is_valid(i, i + 1, input_value)) {
        cvalue += (i + 2 < values.size() ? values[i + 2] : 1);
      }
      values[i] = cvalue;
    }

    return *values.begin();
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
