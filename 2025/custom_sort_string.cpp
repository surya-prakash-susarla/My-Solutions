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
  string customSortString(string target, string input) {
    map<char, int> counts;
    for (char c : input)
      counts[c]++;

    string answer;
    for (char c : target) {
      if (counts[c]) {
        answer += string(counts[c], c);
        counts[c] = 0;
      }
    }

    for (auto i : counts)
      if (i.second)
        answer += string(i.second, i.first);

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
