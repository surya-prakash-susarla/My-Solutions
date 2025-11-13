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
  int maxOperations(string input) {
    int answer = 0;
    int ones = 0;

    for (int i = 0; i < input.size() - 1;) {
      if (input[i] == '1') {
        int end_one = -1;
        for (int j = i + 1; j < input.size(); j++) {
          if (input[j] == '1') {
            end_one = j;
            break;
          } else {
            continue;
          }
        }

        if (end_one == -1) {
          end_one = input.size();
        }

        int diff = min(end_one - i - 1, 1);
        ones++;
        int current = (diff * ones);
        answer += current;

        i = end_one;
      } else {
        i++;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
