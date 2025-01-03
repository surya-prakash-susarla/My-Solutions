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
  int waysToSplitArray(vector<int>& values) {
    typedef long long int llint;

    llint total = 0;
    for (int i : values)
      total += i;

    llint current = 0;

    int answer = 0;

    for (int i = 0; i < values.size() - 1; i++) {
      current += values[i];
      if (current >= total - current)
        answer++;
    }

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
