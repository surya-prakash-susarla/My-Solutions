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
  int longestNiceSubarray(vector<int>& input) {
    vector<int> counter(input.size(), 1);

    int answer = 1;

    for (int i = input.size() - 2; i > -1; i--) {
      int maxlen = counter[i + 1];
      bool failed = false;
      for (int j = 1; j <= maxlen; j++) {
        if (input[i] & input[i + j]) {
          counter[i] = j - 1;
          failed = true;
          break;
        }
      }

      if (failed)
        counter[i]++;
      else
        counter[i] = maxlen + 1;

      answer = max(answer, counter[i]);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
