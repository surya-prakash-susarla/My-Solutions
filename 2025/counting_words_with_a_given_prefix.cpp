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
  int prefixCount(vector<string>& words, string pref) {
    auto is_valid = [](const string& source, const string& target) -> bool {
      return source.size() >= target.size() and
             source.substr(0, target.size()) == target;
    };

    int answer = 0;
    for (auto i : words)
      if (is_valid(i, pref))
        answer++;

    return answer;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
