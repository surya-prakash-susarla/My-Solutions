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
  long long maxArrayValue(vector<int>& input) {
    typedef long long ll;
    ll next_value = *input.rbegin();
    ll answer = *input.rbegin();
    for (int i = input.size() - 2; i > -1; i--) {
      if (input[i] <= next_value) {
        next_value += input[i];
      } else {
        next_value = input[i];
      }
      answer = max(answer, next_value);
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
