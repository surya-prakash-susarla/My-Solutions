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
  vector<int> getAverages(vector<int>& input, int k) {
    vector<int> values(input.size(), -1);
    int avgn = 2 * k + 1;

    typedef unsigned long long ull;

    if (input.size() < avgn)
      return vector<int>(input.size(), -1);

    ull current_sum = 0;
    for (int i = 0; i < avgn; i++)
      current_sum += input[i];

    values[k] = current_sum / avgn;

    for (int i = k + 1; i + k < input.size(); i++) {
      current_sum -= input[i - k - 1];
      current_sum += input[i + k];
      values[i] = current_sum / avgn;
    }

    return values;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
