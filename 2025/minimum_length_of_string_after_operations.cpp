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
  int minimumLength(string s) {
    vector<int> counts(26, 0);
    for (char c : s)
      counts[c - 'a']++;

    int answer = 0;
    for (auto i : counts)
      if (i % 2)
        answer += 1;
      else if (i != 0)
        answer += 2;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
