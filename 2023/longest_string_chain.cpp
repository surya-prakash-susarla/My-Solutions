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
  bool match(const string& a, const string& b) {
    bool failure = false;
    int i = 0;
    int j = 0;
    while (i < a.size() and j < b.size()) {
      if (a[i] == b[j]) {
        i++;
        j++;
        continue;
      }

      if (failure)
        return false;

      failure = true;
      j++;
    }

    return true;
  }

  int longestStrChain(vector<string>& input) {
    map<int, set<string>> values;
    map<string, int> counts;

    for (auto i : input)
      values[i.size()].insert(i);

    {
      auto it = *values.rbegin();
      for (auto i : it.second)
        counts[i] = 1;
    }

    for (auto it = next(values.rbegin()); it != values.rend(); it = next(it)) {
      auto pr = values.find(it->first + 1);
      if (pr == values.end()) {
        for (auto i : it->second)
          counts[i] = max(counts[i], 1);
      } else {
        for (auto i : it->second) {
          counts[i] = counts[i] == 0 ? 1 : counts[i];
          for (auto j : pr->second) {
            if (match(i, j)) {
              counts[i] = max(counts[i], counts[j] + 1);
            }
          }
        }
      }
    }

    int answer = INT_MIN;
    for (auto i : counts)
      answer = max(answer, i.second);
    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
