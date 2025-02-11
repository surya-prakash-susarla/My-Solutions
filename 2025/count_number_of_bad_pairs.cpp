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
  long long countBadPairs(vector<int>& input) {
    unordered_map<int, int> values;

    for (int i = 0; i < input.size(); i++)
      values[input[i] - i]++;

    long long valid = 0;

    auto count = [](long long n) -> long long {
      if (n < 1)
        return 0;
      return (n * (n + 1)) / 2;
    };

    for (auto i : values) {
      valid += (count(i.second - 1));
    }

    return count(input.size() - 1) - valid;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
