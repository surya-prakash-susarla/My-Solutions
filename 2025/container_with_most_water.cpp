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
  int maxArea(vector<int>& input) {
    int left = 0;
    int right = input.size() - 1;

    int answer = 0;
    while (left < right) {
      int current = (right - left) * (min(input[left], input[right]));
      answer = max(answer, current);

      if (input[left] < input[right]) {
        left++;
      } else {
        right--;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
