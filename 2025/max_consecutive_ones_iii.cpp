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
  int longestOnes(vector<int>& input, int k) {
    int maxlen = 0;
    int left = 0;

    int clen = 0;
    int use = 0;

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == 1) {
        clen++;
      } else {
        while (use >= k) {
          if (input[left] == 0)
            use--;
          clen--;
          left++;
        }
        clen++;
        use++;
      }
      maxlen = max(maxlen, clen);
    }

    return maxlen;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
