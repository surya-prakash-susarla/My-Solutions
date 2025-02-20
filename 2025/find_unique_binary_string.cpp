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
  unordered_set<string> values;

  string answer;

  void __rec__(int req, string current) {
    if (req == 0) {
      if (not values.contains(current)) {
        answer = current;
      }
      return;
    }

    if (answer.empty()) {
      __rec__(req - 1, current + "0");
      __rec__(req - 1, current + "1");
    }
  }

  string findDifferentBinaryString(vector<string>& input) {
    values = unordered_set<string>(input.begin(), input.end());

    int n = input[0].size();

    __rec__(n, "");

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
