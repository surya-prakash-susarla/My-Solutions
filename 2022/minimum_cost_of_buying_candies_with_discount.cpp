#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#define in scanf
#define out printf

using namespace std;

// Problem:

typedef long long int llint;
typedef long double ldouble;

class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    vector<int> values(cost);

    sort(values.begin(), values.end());

    int answer = 0;
    int index = values.size() - 1;

    while (index > -1) {
      answer += (values[index] + (index > 0 ? values[index - 1] : 0));
      index -= 3;
    }

    return answer;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  return 0;
}
