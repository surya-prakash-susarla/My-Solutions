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
  int maxArea(vector<int>& values) {
    int answer = 0;
    int left = 0;
    int right = values.size() - 1;

    while (left < right) {
      answer = max(answer, min(values[left], values[right]) * (right - left));
      if (values[left] > values[right]) {
        right--;
      } else {
        left++;
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
