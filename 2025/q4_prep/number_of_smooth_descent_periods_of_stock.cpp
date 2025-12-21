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
  long long getDescentPeriods(vector<int>& input) {
    long long answer = 0;

    auto fact = [](int n) -> long long {
      if (n % 2) {
        return (long long)(n) * (long long)((n + 1) / 2);
      } else {
        return (long long)(n / 2) * (long long)(n + 1);
      }
    };

    for (int i = 0; i < input.size();) {
      int j = i + 1;
      for (; j < input.size(); j++) {
        if (input[j - 1] - input[j] == 1)
          continue;
        else
          break;
      }

      answer += fact(j - i);
      i = j;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
