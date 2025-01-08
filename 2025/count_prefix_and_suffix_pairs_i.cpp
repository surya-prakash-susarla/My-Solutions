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
  static bool is_prefix(const string& source, const string& target) {
    return source == (target.substr(0, source.size()));
  }

  static bool is_suffix(const string& source, const string& target) {
    return source == (target.substr(target.size() - source.size()));
  }

  static bool is_valid(const string& source, const string& target) {
    return is_prefix(source, target) and is_suffix(source, target);
  }

  int countPrefixSuffixPairs(vector<string>& words) {
    int count = 0;

    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        if (is_valid(words[i], words[j])) {
          count++;
        }
      }
    }

    return count;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
