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
  int longestConsecutive(vector<int>& input) {
    unordered_set<int> values(input.begin(), input.end());

    int answer = 0;
    for (int i : values) {
      if (!values.contains(i - 1)) {
        int current = 1;
        for (int j = i + 1; values.contains(j); j++)
          current++;
        answer = max(answer, current);
      }
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
