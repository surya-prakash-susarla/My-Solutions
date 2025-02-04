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
  int maxAscendingSum(vector<int>& input) {
    int current = input[0];
    int answer = current;

    for (int i = 1; i < input.size(); i++) {
      if (input[i] <= input[i - 1])
        current = input[i];
      else
        current += input[i];
      answer = max(answer, current);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
