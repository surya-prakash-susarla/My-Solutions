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
  int minimumRecolors(string input, int k) {
    int whites = 0;
    for (int i = 0; i < k; i++) {
      if (input[i] == 'W')
        whites++;
    }

    int answer = whites;
    for (int i = k; i < input.size(); i++) {
      if (input[i] == 'W') {
        whites++;
      }
      if (input[i - k] == 'W') {
        whites--;
      }

      answer = min(answer, whites);
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
