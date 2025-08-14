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
  string largestGoodInteger(string input) {
    string answer;

    for (int i = 0; i <= input.size() - 3;) {
      string temp = input.substr(i, 3);

      bool broken = false;
      for (int j = 1; j < temp.size(); j++) {
        if (temp[j] != temp[j - 1]) {
          i += j;
          broken = true;
          break;
        }
      }

      if (not broken) {
        if (answer.empty() or temp > answer) {
          answer = temp;
        }
        i = i + 3;
      }
    }
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
